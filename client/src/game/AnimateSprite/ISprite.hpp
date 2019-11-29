//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_ISPRITE_H
#define CPP_RTYPE_2019_ISPRITE_H

#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;
    class ISprite {
    public:
        virtual sf::IntRect run() = 0;
        std::string _texture;

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
