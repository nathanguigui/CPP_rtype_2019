//
// Created by guigui on 11/13/19.
//

#include <client/src/core/Gui/Tools.hpp>
#include "SplashScreen.hpp"

RType::SplashScreen::SplashScreen(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    this->_splashTexture = new sf::Texture();
    this->_backgroundTexture = new sf::Texture();
    this->_splash = new sf::Sprite();
    this->_background = new sf::Sprite();
    //this->_rectSourceSprite = new sf::IntRect(0,0,128,127);
    this->_splashTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_backgroundTexture->loadFromFile("assets/MainMenu/background.jpg");
    this->_lastFrame = 100000;
    this->_currentFrame = 0;
    this->_done = false;
    this->_background->setTexture(*this->_backgroundTexture);
    this->_splash->setTexture(*this->_splashTexture);
    this->boum = new SimpleExplosion();
    this->kill = new SimpleKill();
    this->touch = new SuperTouch();
    this->simpleTouch = new SimpleTouch();

    this->bullet = new SimpleBullet();
    this->master = new MasterBullet();
    this->super1 = new SuperBullet1();
    this->super2 = new SuperBullet2();
    this->super3 = new SuperBullet3();
    this->bomb = new SimpleBomb();
    //this->_splash->setTextureRect(*this->_rectSourceSprite);
}

void RType::SplashScreen::run() {

    auto screenSize = this->_app->getSize();
    this->_splash->setPosition(centerX(screenSize, this->_splash->getGlobalBounds().width, this->_splash->getPosition()));
    this->_splash->setPosition(centerY(screenSize, this->_splash->getGlobalBounds().height, this->_splash->getPosition()));

    if (this->_currentFrame == 0) {
        this->_clock = new sf::Clock();
        this->_splashClock = new sf::Clock();
        this->_splash->setTextureRect(this->simpleTouch->run());
    }

    if (this->_clock->getElapsedTime().asSeconds() > 5) {
        this->_done = true;
        this->_windowState->setSplashDone(true);
        this->_windowState->setIsLoading(true);
    }

    if (this->_clock->getElapsedTime().asSeconds() < 5) {
        if (this->_splashClock->getElapsedTime().asSeconds() > 0.1f)
        {
            this->_splash->setTextureRect(this->simpleTouch->run());
            this->_splashClock->restart();
        }
        _app->draw(*this->_background);
        _app->draw(*this->_splash);
        this->_currentFrame += 1;
    }
}

RType::SplashScreen::~SplashScreen() = default;
