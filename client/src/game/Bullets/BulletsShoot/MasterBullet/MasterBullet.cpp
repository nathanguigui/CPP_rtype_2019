//
// Created by luc4s.p on 11/15/19.
//

#include "MasterBullet.h"

RType::MasterBullet::MasterBullet(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::MasterBullet::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 104;
        this->_rectSourceSprite->width = 80;
        this->_rectSourceSprite->top = 170;
        this->_rectSourceSprite->height = 16;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 185;
        this->_rectSourceSprite->width = 80;
        this->_rectSourceSprite->top = 170;
        this->_rectSourceSprite->height = 16;
        this->step = 1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::MasterBullet::getTexture() {
    return *this->_bulletTexture;
}
