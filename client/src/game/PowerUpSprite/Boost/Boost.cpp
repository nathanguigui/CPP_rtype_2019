//
// Created by luc4s.p on 11/15/19.
//

#include "Boost.h"

RType::Boost::Boost(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::Boost::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 17;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 34;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 51;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 68;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 85;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 102;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 119;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 8) {
        this->_rectSourceSprite->left = 136;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 9) {
        this->_rectSourceSprite->left = 153;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 10) {
        this->_rectSourceSprite->left = 170;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
    } else if (this->step == 11) {
        this->_rectSourceSprite->left = 187;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->step = 0;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::Boost::getTexture() {
    return *this->_bulletTexture;
}
