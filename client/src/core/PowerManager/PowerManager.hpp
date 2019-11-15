//
// Created by guigui on 11/15/19.
//

#ifndef CPP_RTYPE_2019_POWERMANAGER_HPP
#define CPP_RTYPE_2019_POWERMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/Power/Power.hpp"
#include "client/src/core/PowerUp/PowerUp.hpp"
#include "client/src/core/Power/PowerEnum.hpp"

namespace RType {
    using namespace RType;
    class PowerManager {
    public:
        void addPowerUp(PowerUp *powerUp);

        virtual ~PowerManager();

        PowerManager(sf::RenderWindow *app, PowerEnum::PowerDirection direction);

        void initiateShoot();

    private:

        void shoot(PowerUp *powerUp);

        sf::RenderWindow *_app;
        std::vector<Power*> _bulletsDrawn;
        std::vector<PowerUp*> _powerUps;
        PowerEnum::PowerDirection _direction;
    };
}


#endif //CPP_RTYPE_2019_POWERMANAGER_HPP
