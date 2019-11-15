//
// Created by guigui on 11/14/19.
//

#include "DefaultPowerUp.hpp"

RType::DefaultPowerUp::DefaultPowerUp(sf::RenderWindow *app) : _app(app), _animable(false) {
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile("assets/shoot/normal_shoot.png");
}

sf::IntRect &RType::DefaultPowerUp::getSkinRect() {
    auto ret =  new sf::IntRect(34, 7, 16, 4);
    return *ret;
}

sf::Texture *RType::DefaultPowerUp::getTexture() {
    return this->_texture;
}

bool RType::DefaultPowerUp::isAnimable() {
    return this->_animable;
}

RType::PowerEnum::PowerSpeed RType::DefaultPowerUp::getSpeed() {
    return _speed;
}

void RType::DefaultPowerUp::setSpeed(RType::PowerEnum::PowerSpeed speed) {
    _speed = speed;
}
