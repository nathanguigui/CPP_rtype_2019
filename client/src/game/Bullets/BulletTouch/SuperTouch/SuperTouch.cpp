//
// Created by luc4s.p on 11/15/19.
//

#include "SuperTouch.h"

RType::SuperTouch::SuperTouch(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SuperTouch::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 56;
        this->_rectSourceSprite->width = 25;
        this->_rectSourceSprite->top = 203;
        this->_rectSourceSprite->height = 23;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 82;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 200;
        this->_rectSourceSprite->height = 29;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 116;
        this->_rectSourceSprite->width = 41;
        this->_rectSourceSprite->top = 197;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 158;
        this->_rectSourceSprite->width = 49;
        this->_rectSourceSprite->top = 193;
        this->_rectSourceSprite->height = 43;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 209;
        this->_rectSourceSprite->width = 56;
        this->_rectSourceSprite->top = 190;
        this->_rectSourceSprite->height = 49;
        this->step = -1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SuperTouch::getTexture() {
    return *this->_bulletTexture;
}
