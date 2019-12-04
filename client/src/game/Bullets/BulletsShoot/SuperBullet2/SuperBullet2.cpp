//
// Created by luc4s.p on 11/15/19.
//

#include "SuperBullet2.h"

RType::SuperBullet2::SuperBullet2(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::SuperBullet2::~SuperBullet2() {

}

void RType::SuperBullet2::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 232;
        this->_rectSourceSprite->width = 48;
        this->_rectSourceSprite->top = 136;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 168;
        this->_rectSourceSprite->width = 48;
        this->_rectSourceSprite->top = 136;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 1;
    }
    this->step += 1;
}

void RType::SuperBullet2::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SuperBullet2::destroy() {

}

void RType::SuperBullet2::draw() {
    this->run();
}
