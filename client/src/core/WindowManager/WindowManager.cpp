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
    this->_app = new sf::RenderWindow(videoMode, "R-Type");
    this->_state = new WindowState(this->_app);
    this->_eventManager = new Event(this, this->_app, this->_state);
    this->_settings = new Settings(this->_state);
    this->_splashScreen = new SplashScreen(this->_app, this->_state);
    this->_mainMenu = new MainMenu(this->_app, this->_state, nullptr);
    this->_sceneManager = new SceneManager(this->_app, this->_eventManager);
    this->_loadingScreen = new Loading(this->_app, this->_state, 4.0);

    //network need
    auto scene1 = new Scene(this->_app);
    scene1->addPlayer(Player::SkinColours::PLAYER_BLUE);
    auto sceneName = new std::string("scene1");
    this->_sceneManager->addSetCurrentScene(sceneName, scene1, true);
}

void RType::WindowManager::gameLoop() {
    this->_eventManager->addEventableObject((EventableObject*)this->_mainMenu);
    while (_app->isOpen()) {
        this->_app->clear();
        _eventManager->manageEvent();
        this->display();
    }
}

void RType::WindowManager::processParams(int ac, char **av) {
    if (ac < 3)
        throw Exception("Not enough arguments", STARTUP);
    this->checkIp(av[1]);
    this->checkPort(av[2]);
    this->checkUsername(av[3]);
    this->init();
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
        if (!_loadingScreen->isLaunched())
            this->_loadingScreen->launch();
        else
            this->_loadingScreen->check();
    }
}

void RType::WindowManager::displayInMenu() {
    this->_mainMenu->draw();
}

void RType::WindowManager::displayInGame() {
    this->_sceneManager->drawCurrentScene();
}

void RType::WindowManager::checkIp(char *ip) {
    std::vector<std::string> result;
    boost::split(result, ip, boost::is_any_of("."));
    if (result.size() != 4)
        throw Exception("invalid ip", STARTUP);
    for (auto &i : result)
        if (!std::all_of(i.begin(), i.end(), ::isdigit) || i.empty())
            throw Exception("invalid ip", STARTUP);
    this->_serverIp = new std::string(ip);
}

void RType::WindowManager::checkPort(char *port) {
    auto tmp = std::string(port);
    if (!std::all_of(tmp.begin(), tmp.end(), ::isdigit))
        throw Exception("invalid port", STARTUP);
    this->_serverPort = (unsigned short) strtoul(port, nullptr, 0);
}

void RType::WindowManager::checkUsername(char *username) {
    auto tmp = std::string(username);
    if (tmp.find_first_not_of("poiuytrezamlkjhgfdsqnbvcxwPOIUYTREZAMLKJHGFDSQNBVCXW0987654321") != std::string::npos)
        throw Exception("invalid username", STARTUP);
    this->_playerName = new std::string(username);
}
