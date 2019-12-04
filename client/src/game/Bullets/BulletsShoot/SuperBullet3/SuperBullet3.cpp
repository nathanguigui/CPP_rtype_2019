//
// Created by luc4s.p on 11/15/19.
//

#include "SuperBullet3.h"

RType::SuperBullet3::SuperBullet3(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

void RType::SuperBullet3::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 136;
        this->_rectSourceSprite->width = 64;
        this->_rectSourceSprite->top = 154;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 201;
        this->_rectSourceSprite->width = 64;
        this->_rectSourceSprite->top = 154;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 1;
    }
    this->step += 1;
}

void RType::SuperBullet3::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SuperBullet3::destroy() {

}

void RType::SuperBullet3::draw() {
    this->run();
}

