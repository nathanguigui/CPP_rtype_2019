//
// Created by guigui on 11/14/19.
//

#include <tgmath.h>
#include "Power.hpp"
#include "PowerEnum.hpp"

RType::Power::Power(sf::RenderWindow *app, PowerUp *powerUp) : _app(app), _powerUp(powerUp) {
    this->_sprite = new sf::Sprite(*this->_powerUp->getTexture(), this->_powerUp->getSkinRect());
    this->_moveClock = new sf::Clock();
}

RType::Power::~Power() = default;

void RType::Power::draw() {
    if (this->_moveClock->getElapsedTime().asSeconds() > GRAPHICAL_TICK_SEC) {
        if (this->_powerUp->isAnimable())
            this->_sprite->setTextureRect(this->_powerUp->getSkinRect());
        this->move();
    }
}

void RType::Power::destroy() {

}

void RType::Power::setPosition(sf::Vector2f newPos) {
    this->_sprite->setPosition(newPos);
}

sf::Vector2f RType::Power::getPosition() {
    return this->_sprite->getPosition();
}

void RType::Power::move() {
    int move_base = 20;
    int gonna_move = 0;
    switch (this->_direction) {
        case PowerEnum::UP:
            this->_sprite->move(0, -move_base);
            break;
        case PowerEnum::UP_LEFT:
            gonna_move = (int)std::sqrt(move_base^2)/2;
            this->_sprite->move(-gonna_move, -gonna_move);
            break;
        case PowerEnum::LEFT:
            this->_sprite->move(-move_base, 0);
            break;
        case PowerEnum::DOWN_LEFT:
            gonna_move = (int)std::sqrt(move_base^2)/2;
            this->_sprite->move(-gonna_move, gonna_move);
            break;
        case PowerEnum::DOWN:
            this->_sprite->move(0, move_base);
            break;
        case PowerEnum::DOWN_RIGHT:
            gonna_move = (int)std::sqrt(move_base^2)/2;
            this->_sprite->move(gonna_move, gonna_move);
            break;
        case PowerEnum::RIGHT:
            this->_sprite->move(move_base, 0);
            break;
        case PowerEnum::UP_RIGHT:
            gonna_move = (int)std::sqrt(move_base^2)/2;
            this->_sprite->move(gonna_move, -gonna_move);
            break;
    }
    this->_moveClock->restart();
}

RType::PowerUp *RType::Power::getPowerUp() const {
    return _powerUp;
}

void RType::Power::setPowerUp(RType::PowerUp *powerUp) {
    _powerUp = powerUp;
}

RType::PowerEnum::PowerDirection RType::Power::getDirection() const {
    return _direction;
}

void RType::Power::setDirection(RType::PowerEnum::PowerDirection direction) {
    _direction = direction;
}

RType::PowerEnum::PowerSpeed RType::Power::getSpeed() const {
    return _speed;
}

void RType::Power::setSpeed(RType::PowerEnum::PowerSpeed speed) {
    _speed = speed;
}

void RType::Power::start() {
    this->_moveClock->restart();
    this->_sprite->setTextureRect(this->_powerUp->getSkinRect());
}
