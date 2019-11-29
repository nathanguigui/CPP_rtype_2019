//
// Created by guigui on 11/29/19.
//

#include "Timer.hpp"

RType::Timer::Timer(SplashScreen *splashScreen, TcpNetwork *tcpNetwork, MenuManager *menuManager, WindowState *state,
                    Event *eventManager, Loading *loadingScreen, LoadScreen *loadScreen, sf::RenderWindow *app) : _splashScreen(
        splashScreen), _tcpNetwork(tcpNetwork), _menuManager(menuManager), _state(state), _eventManager(eventManager),
                                                                                              _loadingScreen(
                                                                                                      loadingScreen),
                                                                                              _loadScreen(loadScreen),
                                                                                              _app(app) {
    this->_graphicsClock = new sf::Clock();
    this->_eventClock = new sf::Clock();
    this->_eventClock = new sf::Clock();
}

RType::Timer::~Timer() = default;

void RType::Timer::refresh() {
    /// 60 FPS refresh
    if (needRefresh(30, TimersType::GRAPHICS))
        this->refreshGraphics();
    if (needRefresh(120, TimersType::EVENTS))
        this->refreshEvent();
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

bool RType::Timer::needRefresh(int FPS, TimersType type) {
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
