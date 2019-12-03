//
// Created by luc4s.p on 11/15/19.
//

#include "SuperBullet1.h"

RType::SuperBullet1::SuperBullet1(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SuperBullet1::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 200;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 120;
        this->_rectSourceSprite->height = 12;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 249;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 120;
        this->_rectSourceSprite->height = 12;
        this->step = 1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SuperBullet1::getTexture() {
    return *this->_bulletTexture;
}
