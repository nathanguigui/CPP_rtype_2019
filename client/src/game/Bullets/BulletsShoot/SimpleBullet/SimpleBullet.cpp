//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleBullet.h"

RType::SimpleBullet::SimpleBullet() {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_rectSourceSprite = new sf::IntRect();
}

sf::IntRect RType::SimpleBullet::run(int stage) {
    switch(stage){
        case 0:
            this->_rectSourceSprite->left = 215;
            this->_rectSourceSprite->width = 14;
            this->_rectSourceSprite->top = 85;
            this->_rectSourceSprite->height = 12;
        case 1:
            this->_rectSourceSprite->left = 233;
            this->_rectSourceSprite->width = 11;
            this->_rectSourceSprite->top = 87;
            this->_rectSourceSprite->height = 9;
        case 2:
            this->_rectSourceSprite->left = 249;
            this->_rectSourceSprite->width = 16;
            this->_rectSourceSprite->top = 90;
            this->_rectSourceSprite->height = 4;
    }
    return *this->_rectSourceSprite;
}
