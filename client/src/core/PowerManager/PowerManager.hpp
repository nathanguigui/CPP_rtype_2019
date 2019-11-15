//
// Created by guigui on 11/15/19.
//

#ifndef CPP_RTYPE_2019_POWERMANAGER_HPP
#define CPP_RTYPE_2019_POWERMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/Power/Power.hpp"
#include "client/src/core/PowerUp/PowerUp.hpp"
#include "client/src/core/Power/PowerEnum.hpp"
#include "client/src/core/Scene/IScene.hpp"

namespace RType {
    using namespace RType;
    class PowerManager {
    public:

        PowerManager(sf::RenderWindow *app, PowerEnum::PowerDirection direction, IScene *parentScene);

        virtual ~PowerManager();

        /// Add power up to be manager here
        void addPowerUp(PowerUp *powerUp);

        /// Start Telling to shoot
        void initiateShoot(const sf::Vector2f &shootFrom);

    private:

        void shoot(PowerUp *powerUp, const sf::Vector2f &shootFrom);

        sf::RenderWindow *_app;
        std::vector<Power*> _bulletsDrawn;
        std::vector<PowerUp*> _powerUps;
        PowerEnum::PowerDirection _direction;
        IScene *_parentScene;
    };
}


#endif //CPP_RTYPE_2019_POWERMANAGER_HPP
