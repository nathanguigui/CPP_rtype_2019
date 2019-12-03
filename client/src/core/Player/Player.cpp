//
// Created by guigui on 11/14/19.
//

#include <iostream>
#include "Player.hpp"

RType::Player::Player(sf::RenderWindow *app, IScene *parentScene, RType::Player::SkinColours color)
        : _app(app), _parentScene(parentScene), _color(color) {
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile("assets/Player/texture.gif");
    this->_sprite = new sf::Sprite(*this->_texture, Player::getSkinRect(color, PLAYER_NORMAL));
    this->_sprite->scale(1.5151515151, 1.470588235);
    this->initPlayer();
}

void RType::Player::initPlayer() {
    this->_powerManager = new PowerManager(this->_app, PowerEnum::PowerDirection::RIGHT, this->_parentScene);
    auto defaultPower = new DefaultPowerUp(this->_app);
    this->_powerManager->addPowerUp(defaultPower);

}

RType::Player::~Player() = default;

void RType::Player::handleLeft() {
    this->_sprite->move(-12.5, 0);
    if (this->_udpNetwork != nullptr)
        this->_udpNetwork->moveLeft();
}

void RType::Player::handleRight() {
    this->_sprite->move(12.5, 0);
    if (this->_udpNetwork != nullptr)
        this->_udpNetwork->moveRight();
}

void RType::Player::handleUp() {
    this->_sprite->setTextureRect(Player::getSkinRect(PLAYER_PINK, PLAYER_MAX_UP));
    this->_sprite->move(0, -12.5);
    if (this->_udpNetwork != nullptr)
        this->_udpNetwork->moveUp();
}

void RType::Player::handleDown() {
    this->_sprite->setTextureRect(Player::getSkinRect(PLAYER_PINK, PLAYER_MAX_DOWN));
    this->_sprite->move(0, 12.5);
    if (this->_udpNetwork != nullptr)
        this->_udpNetwork->moveDown();
}

void RType::Player::handleEnter() {
    std::cout << "shoot initiated";
    this->_powerManager->initiateShoot();
    if (this->_udpNetwork != nullptr)
        this->_udpNetwork->shoot();
}

void RType::Player::handleKeyReleased() {
    this->_powerManager->handleKeyReleased(this->_sprite->getPosition());
    this->_sprite->setTextureRect(Player::getSkinRect(PLAYER_PINK, PLAYER_NORMAL));
}

void RType::Player::destroy() {

}

const sf::IntRect & RType::Player::getSkinRect(RType::Player::SkinColours color, RType::Player::SkinOrientation orientation) {
    int orientationFactor = 0;
    int colorFactor = 0;
    int textureWidth = 33;
    int textureHeight = 17;
    switch (color) {
        case PLAYER_LIGHT_BLUE:
            colorFactor = 0;
            break;
        case PLAYER_PINK:
            colorFactor = 1;
            break;
        case PLAYER_GREEN:
            colorFactor = 2;
            break;
        case PLAYER_RED:
            colorFactor = 3;
            break;
        case PLAYER_BLUE:
            colorFactor = 4;
            break;
    }
    switch (orientation) {
        case PLAYER_MAX_DOWN:
            orientationFactor = 0;
            break;
        case PLAYER_DOWN:
            orientationFactor = 1;
            break;
        case PLAYER_NORMAL:
            orientationFactor = 2;
            break;
        case PLAYER_UP:
            orientationFactor = 3;
            break;
        case PLAYER_MAX_UP:
            orientationFactor = 4;
            break;
    }
    int xBegin = (orientationFactor * textureWidth);
    int yBegin = (colorFactor * textureHeight);
    auto ret = new sf::IntRect(xBegin, yBegin, 33, 17);
    return *ret;
}

void RType::Player::draw() {
    this->_app->draw(*this->_sprite);
}

void RType::Player::setPosition(sf::Vector2f newPos) {
    this->_sprite->setPosition(newPos);
}

sf::Vector2f RType::Player::getPosition() {
    return this->_sprite->getPosition();
}

void RType::Player::setUdpNetwork(RType::UdpNetwork *network) {
    this->_udpNetwork = network;
}
