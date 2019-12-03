//
// Created by guigui on 11/13/19.
//

#include <client/src/core/Gui/Tools.hpp>
#include "LoadScreen.hpp"

RType::LoadScreen::LoadScreen(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    this->_splashTexture = new sf::Texture();
    this->_backgroundTexture = new sf::Texture();
    this->_splash = new sf::Sprite();
    this->_background = new sf::Sprite();
    this->_splashTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_backgroundTexture->loadFromFile("assets/MainMenu/Background.png");

    this->_background->setTexture(*this->_backgroundTexture);
    this->_splash->setTexture(*this->_splashTexture);

    this->boum = new SimpleExplosion();
    this->kill = new SimpleKill();
    this->touch = new SuperTouch();
    this->simpleTouch = new SimpleTouch();

    this->redenemy = new LittleRed();

    //this->bullet = new SimpleBullet();
    this->master = new MasterBullet();
    this->super1 = new SuperBullet1();
    this->super2 = new SuperBullet2();
    this->super3 = new SuperBullet3();
    this->bomb = new SimpleBomb();

    //this->_splash->setTextureRect(*this->_rectSourceSprite);

    //this->_buffer.loadFromFile("assets/music/splashscreen.wav");    
    //this->_sound.setBuffer(this->_buffer);
    //this->_sound.play();
}

void RType::LoadScreen::run() {

    auto screenSize = this->_app->getSize();
    this->_splash->setPosition(centerX(screenSize, this->_splash->getGlobalBounds().width, this->_splash->getPosition()));
    this->_splash->setPosition(centerY(screenSize, this->_splash->getGlobalBounds().height, this->_splash->getPosition()));

    this->_splash->setTextureRect(this->boum->run());
    _app->draw(*this->_background);
    _app->draw(*this->_splash);
}

RType::LoadScreen::~LoadScreen() = default;
