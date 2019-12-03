//
// Created by luc4s.p on 11/15/19.
//

#include "SuperBullet1.h"

RType::SuperBullet1::SuperBullet1(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}
RType::SuperBullet1::~SuperBullet1() {

}

void RType::SuperBullet1::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 200;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 120;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 249;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 120;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 0;
    }
    this->step += 1;
}

void RType::SuperBullet1::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SuperBullet1::destroy() {

}

void RType::SuperBullet1::draw() {
    this->run();
}
