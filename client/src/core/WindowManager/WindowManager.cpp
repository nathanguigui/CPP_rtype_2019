//
// Created by guigui on 11/12/19.
//

#include "WindowManager.hpp"

RType::WindowManager::WindowManager(const std::string &name): _name(name) {
}

RType::WindowManager::~WindowManager() = default;

int RType::WindowManager::run() {

    this->_state->initState();

    this->gameLoop();

    return RTYPE_noError;
}

void RType::WindowManager::init() {
    auto videoMode = sf::VideoMode(800, 600);
    /// Create app, state, event, sceneManager & settings
    this->_app = new sf::RenderWindow(videoMode, "R-Type");
    this->_state = new WindowState(this->_app);
    this->_eventManager = new Event(this, this->_app, this->_state);
    this->_settings = new Settings(this->_state);
    this->_sceneManager = new SceneManager(this->_app, this->_eventManager);
    /// Create splash, loading, & menu manager
    this->_splashScreen = new SplashScreen(this->_app, this->_state);
    this->_loadingScreen = new Loading(this->_app, this->_state, 4.0);
    this->_loadScreen = new LoadScreen(this->_app, this->_state);

    auto scene1 = new Scene(this->_app);
    scene1->addPlayer(Player::SkinColours::PLAYER_BLUE);
    auto sceneName = new std::string("scene1");
    this->_sceneManager->addSetCurrentScene(sceneName, scene1, true);
}

void RType::WindowManager::gameLoop() {
    this->_menuManager->switchMenu(MENU_MAIN_MENU);
    while (_app->isOpen()) {
        this->_app->clear();
        _eventManager->manageEvent();
        this->display();
    }
}

void RType::WindowManager::processParams(int ac, char **av) {
    this->init();
    if (ac < 3)
        throw Exception("Not enough arguments", STARTUP);
    this->_settings->checkIp(av[1]);
    this->_settings->checkPort(av[2]);
    this->_settings->checkUsername(av[3]);
    this->_tcpNetwork = new TcpNetwork(this->_app, this->_state, this->_settings->getLobbyServerIp(),
                                       this->_settings->getLobbyServerPort(), this->_loadingScreen, this->_settings);
    this->_menuManager = new MenuManager(this->_state, this->_eventManager, this->_app, this->_tcpNetwork,
                                         this->_settings, this->_loadScreen);
    this->_tcpNetwork->setMenuManager((IMenuManager*)this->_menuManager);
    if (DEBUG_RTYPE)
        this->_settings->debugArgs();
}

void RType::WindowManager::display() {
    switch (this->_state->getWindowMode()) {
        case IN_LAUNCH:
            this->displayInLaunch();
            break;
        case IN_MENU:
            this->displayInMenu();
            break;
        case IN_GAME:
            this->displayInGame();
            break;
        case UNDEFINED:
            break;
    }
    _app->display();
}

void RType::WindowManager::displayInLaunch() {
    if (!this->_state->isSplashDone())
        this->_splashScreen->run();
    else if (this->_state->isLoading()) {
        if (!_loadingScreen->isLaunched()) {
            this->_loadingScreen->launch();
            this->_tcpNetwork->connect();
        } else
            this->_loadingScreen->check();
    }
}

void RType::WindowManager::displayInMenu() {
    if (this->_state->isLoading())
        this->_loadScreen->run();
    else
        this->_menuManager->draw();
}

void RType::WindowManager::displayInGame() {
    this->_sceneManager->drawCurrentScene();
}