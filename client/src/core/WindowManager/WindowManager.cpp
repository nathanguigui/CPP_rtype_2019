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
    this->_mainMenu = new MainMenu(this->_app, this->_state);
    this->_sceneManager = new SceneManager(this->_app, this->_eventManager);

    //network need
    auto scene1 = new Scene(this->_app);
    scene1->addPlayer(Player::SkinColours::PLAYER_BLUE);
    auto sceneName = new std::string("scene1");
    this->_sceneManager->addSetCurrentScene(sceneName, scene1, true);
}

void RType::WindowManager::gameLoop() {
    while (_app->isOpen()) {
        this->_app->clear();
        _eventManager->manageEvent();
        this->display();
    }
}

void RType::WindowManager::processParams(int ac, char **av) {
    std::cout << "check arg count and type then throw error if need";
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
        std::cout << "put loading screen here";
        this->_state->setWindowMode(IN_MENU);
        this->_eventManager->addEventableObject((EventableObject*)this->_mainMenu);
    }
        //this._loading.run();
}

void RType::WindowManager::displayInMenu() {
    this->_mainMenu->draw();
}

void RType::WindowManager::displayInGame() {
    this->_sceneManager->drawCurrentScene();
}
