//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_POWER_HPP
#define CPP_RTYPE_2019_POWER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"
#include "client/src/core/PowerUp/PowerUp.hpp"
#include "client/src/core/core.hpp"
#include "client/src/core/Power/PowerEnum.hpp"

namespace RType {
    using namespace RType;
    class Power: public SceneObject {
    public:

        explicit Power(sf::RenderWindow *app, PowerUp *powerUp);

        virtual ~Power();

        void draw() override;

        void destroy() override;

        void setPosition(sf::Vector2f newPos) override;

        sf::Vector2f getPosition() override;

        void move();

        void start();

        PowerUp *getPowerUp() const;

        void setPowerUp(PowerUp *powerUp);

        PowerEnum::PowerDirection getDirection() const;

        void setDirection(PowerEnum::PowerDirection direction);

        PowerEnum::PowerSpeed getSpeed() const;

        void setSpeed(PowerEnum::PowerSpeed speed);


    private:
        sf::RenderWindow *_app;
        sf::Sprite *_sprite{};
        sf::Clock *_moveClock;
        sf::Clock *_networkClock;
        PowerUp *_powerUp;
        PowerEnum::PowerDirection _direction;
        PowerEnum::PowerSpeed  _speed;
    };

}


#endif //CPP_RTYPE_2019_POWER_HPP
