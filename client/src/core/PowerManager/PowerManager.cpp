//
// Created by guigui on 11/15/19.
//

#include "PowerManager.hpp"
#include "client/src/core/Power/PowerEnum.hpp"

RType::PowerManager::PowerManager(sf::RenderWindow *app, PowerEnum::PowerDirection direction, IScene *parentScene)
        : _app(app), _direction(direction), _parentScene(parentScene) {
    this->_shootRateClock = new sf::Clock();
}

RType::PowerManager::~PowerManager() = default;

void RType::PowerManager::addPowerUp(PowerUp *powerUp) {
    this->_powerUps.push_back(powerUp);
}

void RType::PowerManager::initiateShoot() {
    if (!this->_chargingShoot) {
        this->_chargingShoot = true;
        this->_shootRateClock->restart();
    }

}

void RType::PowerManager::shoot(PowerUp *powerUp, const sf::Vector2f &shootFrom) {
    auto bullet = new Power(this->_app, powerUp);
    bullet->setDirection(this->_direction);
    bullet->setSpeed(powerUp->getSpeed());w
    bullet->setPosition(shootFrom);
    bullet->start();
    _parentScene->addSceneObject((SceneObject*)bullet);
    _bulletsDrawn.push_back(bullet);
}

void RType::PowerManager::handleKeyReleased(const sf::Vector2f &shootFrom) {
    if (this->_chargingShoot && this->_shootRateClock->getElapsedTime().asSeconds() > 1) {
        for (auto & _powerUp : this->_powerUps)
            this->shoot(_powerUp, shootFrom);
        this->_shootRateClock->restart();
        this->_chargingShoot = false;
    }
}
