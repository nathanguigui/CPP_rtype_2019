//
// Created by luc4s.p on 11/15/19.
//

#include "Boost.h"

RType::Boost::Boost(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet23.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::Boost::~Boost() {

}

void RType::Boost::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 17;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 34;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 51;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 68;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 5) {
        this->_rectSourceSprite->left = 85;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 6) {
        this->_rectSourceSprite->left = 102;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 7) {
        this->_rectSourceSprite->left = 119;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 8) {
        this->_rectSourceSprite->left = 136;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 9) {
        this->_rectSourceSprite->left = 153;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 10) {
        this->_rectSourceSprite->left = 170;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 11) {
        this->_rectSourceSprite->left = 187;
        this->_rectSourceSprite->width = 17;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 17;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 0;
    }
    this->step += 1;
}

void RType::Boost::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::Boost::destroy() {

}

void RType::Boost::draw() {
    this->run();
}
