//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_TOOLS_HPP
#define CPP_RTYPE_2019_TOOLS_HPP

#include <SFML/System.hpp>

namespace RType {
    sf::Vector2f centerX(sf::Vector2u screenSize, int width, sf::Vector2<float> initialPos);
    sf::Vector2f centerY(sf::Vector2u screenSize, int height, sf::Vector2f initialPos);
    sf::Vector2f linePos(sf::Vector2u screenSize, int height, sf::Vector2<float> initialPos, int factor, int pos);
}

#endif //CPP_RTYPE_2019_TOOLS_HPP
