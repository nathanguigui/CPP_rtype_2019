//
// Created by luc4s.p on 11/15/19.
//

#include "LittleBrown.h"

RType::LittleBrown::LittleBrown(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::LittleBrown::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 33;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 66;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 99;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 132;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 165;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 198;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 231;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->step = 0;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::LittleBrown::getTexture() {
    return *this->_bulletTexture;
}
