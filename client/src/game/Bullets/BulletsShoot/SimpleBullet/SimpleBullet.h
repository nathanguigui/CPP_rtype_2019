//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEBULLET_H
#define CPP_RTYPE_2019_SIMPLEBULLET_H

#include <SFML/Graphics.hpp>
#include "../../../AnimateSprite/ISprite.hpp"

namespace RType {
    using namespace RType;
    class SimpleBullet : public ISprite{
    public:
        SimpleBullet(sf::RenderWindow *app);
        ~SimpleBullet();
        void setPosition(float x, float y);
        sf::Vector2f getPosition() {return _sprite->getPosition();};
        sf::IntRect run();
        sf::Texture getTexture();
        void destroy();
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
