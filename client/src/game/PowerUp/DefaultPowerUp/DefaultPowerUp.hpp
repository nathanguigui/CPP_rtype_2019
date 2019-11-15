//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_DEFAULTPOWERUP_HPP
#define CPP_RTYPE_2019_DEFAULTPOWERUP_HPP

#include "client/src/core/PowerUp/PowerUp.hpp"
#include <SFML/Graphics.hpp>

namespace RType {
    class DefaultPowerUp: public PowerUp {
    public:
        DefaultPowerUp(sf::RenderWindow *app);

        sf::IntRect &getSkinRect() override;
        sf::Texture *getTexture() override;
        bool isAnimable() override;

        PowerEnum::PowerSpeed getSpeed() override;

        void setSpeed(PowerEnum::PowerSpeed speed);

    private:
        sf::RenderWindow *_app;
        sf::Texture *_texture;
        bool _animable;
        PowerEnum::PowerSpeed _speed;
    };
}


#endif //CPP_RTYPE_2019_DEFAULTPOWERUP_HPP
