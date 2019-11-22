//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleTouch.h"

RType::SimpleTouch::SimpleTouch(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SimpleTouch::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 1;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 343;
        this->_rectSourceSprite->height = 28;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 35;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 343;
        this->_rectSourceSprite->height = 28;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 73;
        this->_rectSourceSprite->width = 21;
        this->_rectSourceSprite->top = 349;
        this->_rectSourceSprite->height = 18;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 106;
        this->_rectSourceSprite->width = 22;
        this->_rectSourceSprite->top = 347;
        this->_rectSourceSprite->height = 20;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 138;
        this->_rectSourceSprite->width = 24;
        this->_rectSourceSprite->top = 346;
        this->_rectSourceSprite->height = 22;
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 170;
        this->_rectSourceSprite->width = 26;
        this->_rectSourceSprite->top = 345;
        this->_rectSourceSprite->height = 24;
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 202;
        this->_rectSourceSprite->width = 28;
        this->_rectSourceSprite->top = 344;
        this->_rectSourceSprite->height = 28;
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 233;
        this->_rectSourceSprite->width = 32;
        this->_rectSourceSprite->top = 343;
        this->_rectSourceSprite->height = 28;
        this->step = -1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SimpleTouch::getTexture() {
    return *this->_bulletTexture;
}
