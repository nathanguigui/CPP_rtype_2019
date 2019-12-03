//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleBomb.h"

RType::SimpleBomb::SimpleBomb(): step(0) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SimpleBomb::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 208;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 225;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 242;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 259;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
        this->step = -1;
    }
    this->step += 1;
    return *this->_rectSourceSprite;
}

sf::Texture RType::SimpleBomb::getTexture() {
    return *this->_bulletTexture;
}
