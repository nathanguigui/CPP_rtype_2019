//
// Created by guigui on 11/13/19.
//

#include <client/src/core/Gui/Tools.hpp>

#include "AnimateSprite.hpp"

RType::AnimateSprite::AnimateSprite(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    
    /// texture for sprite
    this->_splashTexture = new sf::Texture();
    this->_backgroundTexture = new sf::Texture();
    
    /// sprites
    this->_splash = new sf::Sprite();
    this->_background = new sf::Sprite();

    /// touch and kill
    this->boum = new SimpleExplosion();
    this->kill = new SimpleKill();
    this->touch = new SuperTouch();
    this->simpleTouch = new SimpleTouch();

    /// enemies
    this->redenemy = new LittleRed();

    this->bullet = new SimpleBullet();
    this->master = new MasterBullet();
    this->super1 = new SuperBullet1();
    this->super2 = new SuperBullet2();
    this->super3 = new SuperBullet3();
    this->bomb = new SimpleBomb();
    
    this->_splashTexture->loadFromFile("assets/uncut_sprites/r-typesheet5.gif");
    this->_lastFrame = 100000;
    this->_currentFrame = 0;
    this->_done = false;
    this->_background->setTexture(*this->_backgroundTexture);
    this->_splash->setTexture(*this->_splashTexture);

    //this->_buffer.loadFromFile("assets/music/splashscreen.wav");    
    //this->_sound.setBuffer(this->_buffer);
    //this->_sound.play();
}

void RType::AnimateSprite::run() {

    auto screenSize = this->_app->getSize();
    this->_splash->setPosition(centerX(screenSize, this->_splash->getGlobalBounds().width, this->_splash->getPosition()));
    this->_splash->setPosition(centerY(screenSize, this->_splash->getGlobalBounds().height, this->_splash->getPosition()));


    if (this->_currentFrame == 0) {
        this->_clock = new sf::Clock();
        this->_splashClock = new sf::Clock();
        this->_splash->setTextureRect(this->redenemy->run());
    }

    if (this->_clock->getElapsedTime().asSeconds() > 7) {
        this->_done = true;
        this->_windowState->setSplashDone(true);
        this->_windowState->setIsLoading(true);
    }

    if (this->_clock->getElapsedTime().asSeconds() < 10) {
        if (this->_splashClock->getElapsedTime().asSeconds() > 0.05f)
        {
            this->_splash->setTextureRect(this->redenemy->run());
            this->_splashClock->restart();
        }
        _app->draw(*this->_background);
        _app->draw(*this->_splash);
        this->_currentFrame += 1;
    }
}

RType::AnimateSprite::~AnimateSprite() = default;
