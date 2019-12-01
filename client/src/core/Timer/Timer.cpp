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
    this->_tcpClock = new sf::Clock();
    this->_udpClock = new sf::Clock();
}

RType::Timer::~Timer() = default;

void RType::Timer::refresh() {
    if (needRefresh(20, TimersType::GRAPHICS))
        this->refreshGraphics();
    if (needRefresh(60, TimersType::EVENTS))
        this->refreshEvent();
    if (needRefresh(2, TimersType::TCP_NETWORK))
        this->refreshTcpNetwork();
    if (needRefresh(15, TimersType::UDP_NETWORK))
        this->refreshUdpNetwork();
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
        case TCP_NETWORK:
            return this->_tcpClock->getElapsedTime().asMilliseconds() > msWaitTime;
        case GRAPHICS:
            return this->_graphicsClock->getElapsedTime().asMilliseconds() > msWaitTime;
        case EVENTS:
            return this->_eventClock->getElapsedTime().asMilliseconds() > msWaitTime;
        case UDP_NETWORK:
            return this->_udpClock->getElapsedTime().asMilliseconds() > msWaitTime;
            break;
    }
    return false;
}

void RType::Timer::refreshTcpNetwork() {
    this->_tcpNetwork->waitForPacket();
    this->_tcpNetwork->update();
    this->_tcpClock->restart();
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
    this->_tcpClock = new sf::Clock();
    this->_udpClock = new sf::Clock();
}

void RType::Timer::refreshUdpNetwork() {
    this->_udpNetwork->update();
    this->_udpNetwork->waitForPacket();
    this->_udpClock->restart();
}
