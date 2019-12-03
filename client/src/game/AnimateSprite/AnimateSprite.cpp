//
// Created by guigui on 11/13/19.
//

#include <client/src/core/Gui/Tools.hpp>
#include "ISprite.hpp"

#include "AnimateSprite.hpp"

RType::AnimateSprite::AnimateSprite(sf::RenderWindow *app, WindowState *state) : _app(app), _windowState(state) {
    
    /// texture for sprite
    this->_splashTexture = new sf::Texture();
    /// sprite
    this->_splash = new sf::Sprite();

    /// sprites
    this->boum = new SimpleExplosion();
    this->kill = new SimpleKill();
    this->simpleTouch = new SimpleTouch();
    this->touch = new SuperTouch();
    this->master = new MasterBullet();
    //this->bullet = new SimpleBullet();
    this->super1 = new SuperBullet1();
    this->super2 = new SuperBullet2();
    this->super3 = new SuperBullet3();
    this->bomb = new SimpleBomb();

    this->redenemy = new LittleRed();

    /// touch and kill
    this->sprites["SimpleExplosion"] = this->boum;
    this->sprites["SimpleTouch"] = this->simpleTouch;
    this->sprites["SuperTouch"] = this->touch;
    this->sprites["SimpleBomb"] = this->bomb;

    /// bullets
    this->sprites["MasterBullet"] = this->master;
    //this->sprites["SimpleBullet"] = this->bullet;
    this->sprites["SuperBullet1"] = this->super1;
    this->sprites["SuperBullet2"] = this->super2;
    this->sprites["SuperBullet3"] = this->super3;

    /// enemies
    this->sprites["LittleRed"] = this->redenemy;

}

void RType::AnimateSprite::run(std::string type, sf::Vector2f x, sf::Vector2f y) {

    //auto screenSize = this->_app->getSize();
    this->_splash->setPosition(x);//(centerX(screenSize, this->_splash->getGlobalBounds().width, this->_splash->getPosition()));
    this->_splash->setPosition(y);//(centerY(screenSize, this->_splash->getGlobalBounds().height, this->_splash->getPosition()));

    if (type == "MasterBullet" || type == "SimpleBullet" || type == "SuperBullet1") {
        this->_buffer.loadFromFile("assets/music/tatata.wav");    
        this->_sound.setBuffer(this->_buffer);
        this->_sound.play();
    }

    this->_splashClock = new sf::Clock();
    this->_splashTexture->loadFromFile(this->sprites[type]->_texture);
    this->_splash->setTexture(*this->_splashTexture);
    this->_splash->setTextureRect(this->sprites[type]->run());

    if (this->_splashClock->getElapsedTime().asSeconds() > 0.05f)
    {
        this->_splash->setTextureRect(this->sprites[type]->run());
        this->_splashClock->restart();
    }
    _app->draw(*this->_splash);
}

RType::AnimateSprite::~AnimateSprite() = default;
