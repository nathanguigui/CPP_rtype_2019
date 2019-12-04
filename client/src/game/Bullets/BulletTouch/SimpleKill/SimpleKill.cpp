//
// Created by luc4s.p on 11/15/19.
//

#include "SimpleKill.h"

RType::SimpleKill::SimpleKill(sf::RenderWindow *app): step(0), _app(app) {
    this->_killTexture = new sf::Texture();
    this->_killTexture->loadFromFile("assets/bullets/r-typesheet44.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_killTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::SimpleKill::~SimpleKill() {

}

void RType::SimpleKill::run() {
    if (this->step == 0) {
            this->_rectSourceSprite->left = 129;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
    } else if (this->step == 1) {
            this->_rectSourceSprite->left = 161;
            this->_rectSourceSprite->width = 32;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
    } else if (this->step == 2) {
            this->_rectSourceSprite->left = 194;
            this->_rectSourceSprite->width = 32;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
    } else if (this->step == 3) {
            this->_rectSourceSprite->left = 228;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
    } else if (this->step == 4) {
            this->_rectSourceSprite->left = 261;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 2;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
    } else if (this->step == 5) {
            this->_rectSourceSprite->left = 294;
            this->_rectSourceSprite->width = 31;
            this->_rectSourceSprite->top = 1;
            this->_rectSourceSprite->height = 32;
                this->_sprite->setTextureRect(*this->_rectSourceSprite);
                _app->draw(*this->_sprite);
            this->step = -1;
    }
    this->step += 1;
}

void RType::SimpleKill::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::SimpleKill::destroy() {

}

void RType::SimpleKill::draw() {
    this->run();
}