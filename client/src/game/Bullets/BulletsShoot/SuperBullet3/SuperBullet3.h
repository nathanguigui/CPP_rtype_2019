//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SUPERBULLET3_H
#define CPP_RTYPE_2019_SUPERBULLET3_H

#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;
    class SuperBullet3 {
    public:
        SuperBullet3();
        ~SuperBullet3();
        sf::IntRect run();
        sf::Texture getTexture();

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
        int step;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
