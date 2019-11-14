//
// Created by guigui on 11/14/19.
//

#include "Power.hpp"

RType::Power::Power(sf::RenderWindow *app, PowerUp *powerUp) : _app(app), _powerUp(powerUp) {
    this->_sprite = new sf::Sprite(*this->_powerUp->getTexture(), this->_powerUp->getSkinRect());
}

RType::Power::~Power() = default;

void RType::Power::draw() {

}

void RType::Power::destroy() {

}

void RType::Power::setPosition(sf::Vector2f newPos) {
    this->_sprite->setPosition(newPos);
}

sf::Vector2f RType::Power::getPosition() {
    return this->_sprite->getPosition();
}
