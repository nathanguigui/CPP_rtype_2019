//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEBULLET_H
#define CPP_RTYPE_2019_SIMPLEBULLET_H

#include <SFML/Graphics.hpp>
#include <client/src/core/SceneObject/SceneObject.hpp>
#include "../../../AnimateSprite/ISprite.hpp"

namespace RType {
    using namespace RType;
    class SimpleBullet : public SceneObject, public ISprite{
    public:
        explicit SimpleBullet(sf::RenderWindow *app);
        ~SimpleBullet();

        void setPosition(sf::Vector2f pos) override;

        sf::Vector2f getPosition() override {return _sprite->getPosition();};

        sf::IntRect run();

        sf::Texture getTexture();

        void draw() override ;

        void destroy() override;

        std::string _texture = "assets/bullets/r-typesheet1.gif";

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
        int step;
        sf::RenderWindow *_app;
        sf::Sprite *_sprite;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
