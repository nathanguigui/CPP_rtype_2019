//
// Created by luc4s.p on 11/15/19.
//

#include "OrangeBoss.h"

RType::OrangeBoss::OrangeBoss(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/uncut_sprites:r-typesheet14.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::OrangeBoss::~OrangeBoss() {

}

void RType::OrangeBoss::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 0;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 50;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 2) {
        this->_rectSourceSprite->left = 100;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 3) {
        this->_rectSourceSprite->left = 150;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 4) {
        this->_rectSourceSprite->left = 200;
        this->_rectSourceSprite->width = 50;
        this->_rectSourceSprite->top = 0;
        this->_rectSourceSprite->height = 50;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 0;
    }
    this->step += 1;
}

void RType::OrangeBoss::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::OrangeBoss::destroy() {

}

void RType::OrangeBoss::draw() {
    this->run();
}
