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
    this->_gameTimer = new Timer(this, this->_app);
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
    this->_tcpNetwork = new TcpNetwork(this->_app, this);
    this->_soundManager = new SoundManager(this->_settings);
    this->_menuManager = new MenuManager(this->_app, this);
    this->_udpNetwork = new UdpNetwork(this->_app, this->_state, this->_settings->getLobbyServerIp(), 25567,
                                       this->_settings, this);
    if (DEBUG_RTYPE)
        this->_settings->debugArgs();
}

RType::CoreObject *RType::WindowManager::getEvent() {
    return this->_eventManager;
}

RType::CoreObject *RType::WindowManager::getLoading() {
    return this->_loadingScreen;
}

RType::CoreObject *RType::WindowManager::getLoadScreen() {
    return this->_loadScreen;
}

RType::CoreObject *RType::WindowManager::getLogger() {
    // TODO add logger
    return nullptr;
}

RType::CoreObject *RType::WindowManager::getSceneManager() {
    return this->_sceneManager;
}

RType::CoreObject *RType::WindowManager::getSettings() {
    return this->_settings;
}

RType::CoreObject *RType::WindowManager::getSoundManager() {
    return this->_soundManager;
}

RType::CoreObject *RType::WindowManager::getSplashScreen() {
    return this->_splashScreen;
}

RType::CoreObject *RType::WindowManager::getWindowState() {
    return this->_state;
}

RType::CoreObject *RType::WindowManager::getTimer() {
    return this->_gameTimer;
}

RType::CoreObject *RType::WindowManager::getUdpNetwork() {
    return this->_udpNetwork;
}

RType::CoreObject *RType::WindowManager::getTcpNetwork() {
    return this->_tcpNetwork;
}

RType::CoreObject *RType::WindowManager::getMenuManager() {
    return this->_menuManager;
}

