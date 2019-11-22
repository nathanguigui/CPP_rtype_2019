//
// Created by luc4s.p on 11/15/19.
//

#include "SuperBullet2.h"

RType::SuperBullet2::SuperBullet2(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SuperBullet2::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 232;
        this->_rectSourceSprite->width = 16;
        this->_rectSourceSprite->top = 102;
        this->_rectSourceSprite->height = 13;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 249;
        this->_rectSourceSprite->width = 16;
        this->_rectSourceSprite->top = 104;
        this->_rectSourceSprite->height = 9;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 168;
        this->_rectSourceSprite->width = 48;
        this->_rectSourceSprite->top = 137;
        this->_rectSourceSprite->height = 12;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 217;
        this->_rectSourceSprite->width = 48;
        this->_rectSourceSprite->top = 136;
        this->_rectSourceSprite->height = 14;
        this->step = 1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SuperBullet2::getTexture() {
    return *this->_bulletTexture;
}
