//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleBomb.h"

RType::SimpleBomb::SimpleBomb(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::SimpleBomb::~SimpleBomb() {

}

void RType::SimpleBomb::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 208;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 225;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 242;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 259;
        this->_rectSourceSprite->width = 14;
        this->_rectSourceSprite->top = 276;
        this->_rectSourceSprite->height = 12;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = -1;
    }
    this->step += 1;
}

void RType::SimpleBomb::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SimpleBomb::destroy() {

}

void RType::SimpleBomb::draw() {
    this->run();
}
