//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_ORANGEBOSS_H
#define CPP_RTYPE_2019_ORANGEBOSS_H

#include <SFML/Graphics.hpp>
#include "../../AnimateSprite/ISprite.hpp"

namespace RType {
    using namespace RType;
    class OrangeBoss : public ISprite {
    public:
        OrangeBoss();
        ~OrangeBoss();
        sf::IntRect run();
        sf::Texture getTexture();
        std::string _texture = "assets/uncun_sprites/r-typesheet14.gif";

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
        int step;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
