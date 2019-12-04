//
// Created by luc4s.p on 11/15/19.
//

#include "Heal.h"

RType::Heal::Heal(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::Heal::~Heal() {

}

void RType::Heal::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 155;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 173;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 191;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 209;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 227;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 245;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 263;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 281;
        this->_rectSourceSprite->width = 18;
        this->_rectSourceSprite->top = 315;
        this->_rectSourceSprite->height = 14;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 0;
    }
    this->step += 1;
}

void RType::Heal::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::Heal::destroy() {

}

void RType::Heal::draw() {
    this->run();
}
