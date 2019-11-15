//
// Created by glithaud on 11/15/19.
//

#ifndef CPP_RTYPE_2019_LOADING_HPP
#define CPP_RTYPE_2019_LOADING_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/CoreObject/CoreObject.hpp"
#include "client/src/core/WindowState/WindowState.hpp"

namespace RType {
    using namespace RType;
    class Loading : public CoreObject {
    public:
        explicit Loading(sf::RenderWindow *app, WindowState *state, float timer);
        virtual ~Loading();

        WindowMode getNextMode();
        void setNextMode(WindowMode mode);

        float getTimeToWait();
        void setTimeToWait(float time);

        void launch();
        bool isLaunched();
        void check();
        void stop();

    private:
        sf::RenderWindow *_app;
        sf::Texture *_backTexture;
        sf::Sprite _backSprite;
        WindowMode _nextmode;
        float _timeToWait;
        sf::Clock *_clock;
        sf::Time _time;
        bool _isLaunched;
        WindowState *_state;
        WindowMode _mode;
        bool _first = true;
    };
}


#endif //CPP_RTYPE_2019_LOADING_HPP
