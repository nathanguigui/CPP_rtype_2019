//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleBullet.h"

RType::SimpleBullet::SimpleBullet(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::SimpleBullet::~SimpleBullet() {

}

void RType::SimpleBullet::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 214;
        this->_rectSourceSprite->width = 16;
        this->_rectSourceSprite->top = 85;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 231;
        this->_rectSourceSprite->width = 16;
        this->_rectSourceSprite->top = 85;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {        
        this->_rectSourceSprite->left = 249;
        this->_rectSourceSprite->width = 16;
        this->_rectSourceSprite->top = 85;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 1;
    }
    this->step += 1;
}

void RType::SimpleBullet::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SimpleBullet::destroy() {

}

void RType::SimpleBullet::draw() {
    this->run();
}