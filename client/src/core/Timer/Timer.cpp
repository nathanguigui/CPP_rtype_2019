//
// Created by guigui on 11/29/19.
//

#include "Timer.hpp"

RType::Timer::Timer(SplashScreen *splashScreen, TcpNetwork *tcpNetwork, MenuManager *menuManager, WindowState *state,
                    Event *eventManager, Loading *loadingScreen, LoadScreen *loadScreen, sf::RenderWindow *app,
                    SceneManager *sceneManager) : _splashScreen(
        splashScreen), _tcpNetwork(tcpNetwork), _menuManager(menuManager), _state(state), _eventManager(eventManager),
                                                  _loadingScreen(
                                                                                                      loadingScreen),
                                                  _loadScreen(loadScreen),
                                                  _app(app), _sceneManager(sceneManager) {
    this->_graphicsClock = new sf::Clock();
    this->_eventClock = new sf::Clock();
    this->_networkClock = new sf::Clock();
}

RType::Timer::~Timer() = default;

void RType::Timer::refresh() {
    /// 60 FPS refresh
    if (needRefresh(30, TimersType::GRAPHICS))
        this->refreshGraphics();
    if (needRefresh(120, TimersType::EVENTS))
        this->refreshEvent();
    if (needRefresh(1, TimersType::NETWORK))
        this->refreshNetwork();
}

void RType::Timer::refreshGraphics() {
    this->_app->clear();
    switch (this->_state->getWindowMode()) {
        case IN_LAUNCH:
            this->refreshSplashScreen();
            break;
        case IN_MENU:
            this->refreshMenu();
            break;
        case IN_GAME:
            this->refreshGame();
            break;
        case UNDEFINED:
            break;
    }
    _app->display();
    this->_graphicsClock->restart();
}

void RType::Timer::refreshSplashScreen() {
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

void RType::Timer::refreshMenu() {
    if (this->_state->isLoading())
        this->_loadScreen->run();
    else
        this->_menuManager->draw();
}

void RType::Timer::refreshGame() {
    this->_sceneManager->drawCurrentScene();
}

void RType::Timer::refreshEvent() {
    _eventManager->manageEvent();
    this->_eventClock->restart();
}

bool RType::Timer::needRefresh(float FPS, TimersType type) {
    float msWaitTime = 1000 / FPS;
    switch (type) {
        case NETWORK:
            return this->_networkClock->getElapsedTime().asMilliseconds() > msWaitTime;
        case GRAPHICS:
            return this->_graphicsClock->getElapsedTime().asMilliseconds() > msWaitTime;
        case EVENTS:
            return this->_eventClock->getElapsedTime().asMilliseconds() > msWaitTime;
    }
    return false;
}

void RType::Timer::refreshNetwork() {
    this->_tcpNetwork->waitForPacket();
    std::cout << "Network is refreshing\r\n";
    this->_networkClock->restart();
}

RType::Timer::Timer(IWindowManager *parent, sf::RenderWindow *app) : _parent(parent), _app(app) {
    this->_splashScreen = (SplashScreen*)_parent->getSplashScreen();
    this->_tcpNetwork = (TcpNetwork*)_parent->getTcpNetwork();
    this->_udpNetwork = (UdpNetwork*)_parent->getUdpNetwork();
    this->_menuManager = (MenuManager*)_parent->getMenuManager();
    this->_state = (WindowState*)_parent->getWindowState();
    this->_eventManager = (Event*)_parent->getEvent();
    this->_sceneManager = (SceneManager*)_parent->getSceneManager();
    this->_loadingScreen = (Loading*)_parent->getLoading();
    this->_loadScreen = (LoadScreen*)_parent->getLoadScreen();
    this->_graphicsClock = new sf::Clock();
    this->_eventClock = new sf::Clock();
    this->_networkClock = new sf::Clock();
}
