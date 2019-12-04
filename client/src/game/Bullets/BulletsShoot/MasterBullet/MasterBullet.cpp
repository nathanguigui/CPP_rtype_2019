//
// Created by luc4s.p on 11/15/19.
//

#include "MasterBullet.h"

RType::MasterBullet::MasterBullet(sf::RenderWindow *app): step(0), _app(app) {
    this->_bulletTexture = new sf::Texture();
    this->_bulletTexture->loadFromFile("assets/bullets/r-typesheet1.gif");
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*this->_bulletTexture);
    this->_rectSourceSprite = new sf::IntRect();
}

RType::MasterBullet::~MasterBullet() {

}

void RType::MasterBullet::run() {
    if (this->step == 0) {
        this->_rectSourceSprite->left = 104;
        this->_rectSourceSprite->width = 80;
        this->_rectSourceSprite->top = 170;
        this->_rectSourceSprite->height = 16;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
    } else if (this->step == 1) {
        this->_rectSourceSprite->left = 185;
        this->_rectSourceSprite->width = 80;
        this->_rectSourceSprite->top = 170;
        this->_rectSourceSprite->height = 16;
        this->_sprite->setTextureRect(*this->_rectSourceSprite);
        _app->draw(*this->_sprite);
        this->step = 1;
    }
    this->step += 1;
}

void RType::MasterBullet::setPosition(sf::Vector2f pos) {
    _sprite->setPosition(pos);
}

void RType::MasterBullet::destroy() {

}

void RType::MasterBullet::draw() {
    this->run();
}
