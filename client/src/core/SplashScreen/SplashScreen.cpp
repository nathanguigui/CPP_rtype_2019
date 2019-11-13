//
// Created by guigui on 11/13/19.
//

#include "SplashScreen.hpp"

RType::SplashScreen::SplashScreen(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    this->_currentTexture = new sf::Texture();
    this->_currentTexture->loadFromFile("assets/SplashScreen/background.png");
    this->_lastFrame = 300;
    this->_currentFrame = 0;
    this->_done = false;
}

void RType::SplashScreen::run() {
    if (this->_currentFrame == this->_lastFrame)
        this->_done = true;
    if (!this->_done) {
        this->_currentFrame += 1;
    }
}

RType::SplashScreen::~SplashScreen() = default;
