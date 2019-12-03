//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEKILL_H
#define CPP_RTYPE_2019_SIMPLEKILL_H

#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;
    class SimpleKill {
    public:
        SimpleKill();
        ~SimpleKill();
        sf::IntRect run();
        std::string _texture = "assets/bullets/r-typesheet44.gif";

    private:
        int step;
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_killTexture;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEKILL_H
