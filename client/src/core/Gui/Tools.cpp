//
// Created by guigui on 11/13/19.
//

#include "Tools.hpp"

sf::Vector2f RType::centerX(sf::Vector2u screenSize, int width, sf::Vector2<float> initialPos) {
    initialPos.x = screenSize.x / 2 - width / 2;
    return initialPos;
}
sf::Vector2f RType::centerY(sf::Vector2u screenSize, int height, sf::Vector2f initialPos) {
    initialPos.y = screenSize.y / 2 - height / 2;
    return initialPos;
}
sf::Vector2f RType::linePos(sf::Vector2u screenSize, int height, sf::Vector2<float> initialPos, int factor, int pos) {
    initialPos.y = (screenSize.y / ((factor + 1)) * pos) - height / 2;
    return initialPos;
}