//
// Created by luc4s.p on 11/15/19.
//

#include "OrangeBoss.h"

RType::OrangeBoss::OrangeBoss(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::OrangeBoss::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 50;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 100;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 150;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 200;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->step = 0;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::OrangeBoss::getTexture() {
    return *this->_bulletTexture;
}
