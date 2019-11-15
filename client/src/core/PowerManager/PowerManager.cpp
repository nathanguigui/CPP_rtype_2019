//
// Created by guigui on 11/15/19.
//

#include "PowerManager.hpp"
#include "client/src/core/Power/PowerEnum.hpp"

RType::PowerManager::PowerManager(sf::RenderWindow *app, PowerEnum::PowerDirection direction) : _app(app), _direction(direction) {

}

RType::PowerManager::~PowerManager() = default;

void RType::PowerManager::addPowerUp(PowerUp *powerUp) {
    this->_powerUps.push_back(powerUp);
}

void RType::PowerManager::initiateShoot() {
    for (auto & _powerUp : this->_powerUps)
        this->shoot(_powerUp);

}

void RType::PowerManager::shoot(RType::PowerUp *powerUp) {
    auto bullet = new Power(this->_app, powerUp);
    bullet->setDirection(this->_direction);
    bullet->setSpeed(powerUp->getSpeed());
}
