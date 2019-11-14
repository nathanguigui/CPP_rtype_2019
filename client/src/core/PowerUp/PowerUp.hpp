//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_POWERUP_HPP
#define CPP_RTYPE_2019_POWERUP_HPP

#include <SFML/Graphics.hpp>

namespace RType {
    class PowerUp {
    public:
        virtual sf::IntRect &getSkinRect() = 0;
        virtual sf::Texture *getTexture() = 0;
    };
}


#endif //CPP_RTYPE_2019_POWERUP_HPP
