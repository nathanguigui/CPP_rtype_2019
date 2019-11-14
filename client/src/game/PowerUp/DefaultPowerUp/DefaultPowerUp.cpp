//
// Created by guigui on 11/14/19.
//

#include "DefaultPowerUp.hpp"

RType::DefaultPowerUp::DefaultPowerUp(sf::RenderWindow *app) : _app(app) {
    this->_texture = new sf::Texture();
}

sf::IntRect &RType::DefaultPowerUp::getSkinRect() {
    sf::IntRect ret(0, 0, 0, 0);
    return ret;
}

sf::Texture *RType::DefaultPowerUp::getTexture() {
    return this->_texture;
}
