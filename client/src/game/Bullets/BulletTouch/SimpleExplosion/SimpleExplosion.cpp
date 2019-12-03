//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleExplosion.h"

RType::SimpleExplosion::SimpleExplosion(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SimpleExplosion::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 247;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 296;
        this->_rectSourceSprite->height = 31;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 217;
        this->_rectSourceSprite->width = 27;
        this->_rectSourceSprite->top = 296;
        this->_rectSourceSprite->height = 31;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 182;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 296;
        this->_rectSourceSprite->height = 31;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 146;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 296;
        this->_rectSourceSprite->height = 31;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 72;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 296;
        this->_rectSourceSprite->height = 31;
        this->step = -1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SimpleExplosion::getTexture() {
    return *this->_bulletTexture;
}
