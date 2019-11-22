//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SUPERBULLET2_H
#define CPP_RTYPE_2019_SUPERBULLET2_H

#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;
    class SuperBullet2 {
    public:
        SuperBullet2();
        ~SuperBullet2();
        sf::IntRect run();
        sf::Texture getTexture();

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
        int step;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
