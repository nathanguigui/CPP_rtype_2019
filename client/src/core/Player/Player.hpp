//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/EventableSceneObject/EventableSceneObject.hpp"
#include "client/src/core/PowerManager/PowerManager.hpp"
#include "client/src/game/PowerUp/DefaultPowerUp/DefaultPowerUp.hpp"
#include "client/src/core/Scene/IScene.hpp"

namespace RType{
    using namespace RType;


    class Player: public EventableSceneObject {
    public:
        enum SkinColours {
            PLAYER_LIGHT_BLUE,
            PLAYER_PINK,
            PLAYER_GREEN,
            PLAYER_RED,
            PLAYER_BLUE
        };
        enum SkinOrientation {
            PLAYER_MAX_DOWN,
            PLAYER_DOWN,
            PLAYER_NORMAL,
            PLAYER_UP,
            PLAYER_MAX_UP
        };
        explicit Player(sf::RenderWindow *app, IScene *parentScene, RType::Player::SkinColours color);
        virtual ~Player();


        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
        void destroy() override;
        void draw() override;
        void setPosition(sf::Vector2f newPos) override;
        sf::Vector2f getPosition() override;

    private:
        void initPlayer();
        enum SkinSize {
            HEIGHT = 17,
            WIDTH = 33
        };

        static const sf::IntRect &getSkinRect(SkinColours color, SkinOrientation orientation);

        sf::RenderWindow *_app;
        sf::Sprite *_sprite;
        sf::Texture *_texture;
        SkinColours _color;
        PowerManager *_powerManager{};
        IScene *_parentScene;
    };
}


#endif //CPP_RTYPE_2019_PLAYER_HPP
