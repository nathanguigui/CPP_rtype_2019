//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEBULLET_H
#define CPP_RTYPE_2019_SIMPLEBULLET_H

#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;
    class SimpleBullet {
    public:
        SimpleBullet();
        ~SimpleBullet();
        sf::IntRect run(int);

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
