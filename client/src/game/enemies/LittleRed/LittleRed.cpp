//
// Created by luc4s.p on 11/15/19.
//

#include "LittleRed.h"

RType::LittleRed::LittleRed(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::LittleRed::~LittleRed() {

}

void RType::LittleRed::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 33;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 66;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 99;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 132;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 165;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 198;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 231;
        this->_rectSourceSprite->width = 33;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 35;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 0;
    }
    this->step += 1;
}

void RType::LittleRed::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::LittleRed::destroy() {

}

void RType::LittleRed::draw() {
    this->run();
}
