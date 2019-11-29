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
    this->_gameTimer = new Timer(this->_splashScreen, this->_tcpNetwork, this->_menuManager, this->_state,
                                 this->_eventManager, this->_loadingScreen, this->_loadScreen, this->_app);
    while (_app->isOpen())
        this->_gameTimer->refresh();
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

