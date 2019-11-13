//
// Created by guigui on 11/13/19.
//

#include "SplashScreen.hpp"

RType::SplashScreen::SplashScreen(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    this->_currentTexture = new sf::Texture();
    this->_currentTexture->loadFromFile("assets/SplashScreen/background.png");
    this->_lastFrame = 100000;
    this->_currentFrame = 0;
    this->_done = false;
    this->_splash.setTexture(*this->_currentTexture);
}

void RType::SplashScreen::run() {
    if (this->_currentFrame == this->_lastFrame || this->_clock.getElapsedTime().asSeconds() == 3)
        this->_done = true;
        this->_windowState->setSplashDone(true);
        this->_windowState->setIsLoading(true);
    if (!this->_done || this->_clock.getElapsedTime().asSeconds() < 3) {
        this->_currentFrame += 1;
        _app->clear();
        _app->draw(_splash);
    }
}

RType::SplashScreen::~SplashScreen() = default;
