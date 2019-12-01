#ifndef CPP_RTYPE_2019_SOUNDMANAGER_HPP
#define CPP_RTYPE_2019_SOUNDMANAGER_HPP

#include "client/src/core/Sounds/MenuSelectSound/MenuSelectSound.hpp"
#include "client/src/core/Sounds/QuitSound/QuitSound.hpp"
#include "client/src/core/Sounds/MenuMusic/MenuMusic.hpp"
#include "../Settings/Settings.hpp"

namespace RType {
    using namespace RType;
    class SoundManager: public CoreObject {
        public:

            SoundManager(Settings *);
            ~SoundManager();
            void play(std::string type);
            void stop(std::string type);
            void setVol();

        private:

            Settings *_settings;

            MenuMusic *_music;
            MenuSelectSound *_selected;
            QuitSound *_quit;
    };
}

#endif