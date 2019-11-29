//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_MENUMUSIC_H
#define CPP_RTYPE_2019_MENUMUSIC_H

#include <SFML/Audio.hpp>

namespace RType {
    using namespace RType;
    class MenuMusic {
    public:
        MenuMusic();
        ~MenuMusic();
        void run();
        void stop();

    private:
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
        sf::Clock *_clock;

    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
