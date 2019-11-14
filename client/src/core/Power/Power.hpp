//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_POWER_HPP
#define CPP_RTYPE_2019_POWER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"
#include "client/src/core/PowerUp/PowerUp.hpp"

namespace RType {
    class Power: public SceneObject {
    public:
        explicit Power(sf::RenderWindow *app, PowerUp *powerUp);
        virtual ~Power();
        void draw() override;
        void destroy() override;
        void setPosition(sf::Vector2f newPos) override;
        sf::Vector2f getPosition() override;


    private:
        sf::RenderWindow *_app;
        sf::Sprite *_sprite{};
        PowerUp *_powerUp;
    };

}


#endif //CPP_RTYPE_2019_POWER_HPP
