//
// Created by luc4s.p on 11/15/19.
//

#include "Heal.h"

RType::Heal::Heal(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::Heal::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 155;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 173;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 191;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 209;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 227;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 245;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 263;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 281;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->step = 0;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::Heal::getTexture() {
    return *this->_bulletTexture;
}
