//
// Created by guigui on 11/14/19.
//

#include <iostream>
#include "Player.hpp"

RType::Player::Player(sf::RenderWindow *app, RType::Player::SkinColours color) : _app(app), _color(color) {
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile("assets/Player/texture.gif");
    this->_sprite = new sf::Sprite(*this->_texture, Player::getSkinRect(PLAYER_PINK, PLAYER_NORMAL));
}

RType::Player::~Player() = default;

void RType::Player::handleLeft() {

}

void RType::Player::handleRight() {

}

void RType::Player::handleUp() {

}

void RType::Player::handleDown() {

}

void RType::Player::handleEnter() {

}

void RType::Player::handleKeyReleased() {

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
