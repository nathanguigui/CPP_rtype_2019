//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleKill.h"

RType::SimpleKill::SimpleKill() {
    this->_killTexture = new sf::Texture();
    this->_killTexture->loadFromFile("assets/bullets/r-typesheet44.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SimpleKill::run(int stage) {
    switch(stage){
        case 0:
            this->_rectSourceSprite->left = 129;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 29;
        case 1:
            this->_rectSourceSprite->left = 161;
            this->_rectSourceSprite->width = 32;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 32;
        case 2:
            this->_rectSourceSprite->left = 194;
            this->_rectSourceSprite->width = 32;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 32;
        case 3:
            this->_rectSourceSprite->left = 228;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 30;
        case 4:
            this->_rectSourceSprite->left = 261;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 30;
        case 5:
            this->_rectSourceSprite->left = 294;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 31;
    }
    return *this->_rectSourceSprite;
}