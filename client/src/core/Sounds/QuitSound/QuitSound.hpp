//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_QUITSOUND_HPP
#define CPP_RTYPE_2019_QUITSOUND_HPP

#include <SFML/Audio.hpp>

namespace RType {
    using namespace RType;
    class QuitSound {
    public:
        QuitSound();
        ~QuitSound();
        void run();
        void setVol(int vol);

    private:
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
        sf::Clock *_clock;

    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
