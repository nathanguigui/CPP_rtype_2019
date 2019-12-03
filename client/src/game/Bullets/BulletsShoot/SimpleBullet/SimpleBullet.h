//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEBULLET_H
#define CPP_RTYPE_2019_SIMPLEBULLET_H

#include <SFML/Graphics.hpp>
#include "../../../AnimateSprite/ISprite.hpp"
 
namespace RType {
    using namespace RType;
    class SimpleBullet {
    public:
        SimpleBullet(sf::RenderWindow *app);
        ~SimpleBullet();
        void setPosition(float x, float y);
        sf::Vector2f getPosition() {return _sprite->getPosition();};
        void run();
        void destroy();

    private:
        sf::IntRect *_rectSourceSprite{};
        sf::Texture *_bulletTexture;
        sf::RenderWindow *_app;
        sf::Sprite *_sprite;
        int step;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
