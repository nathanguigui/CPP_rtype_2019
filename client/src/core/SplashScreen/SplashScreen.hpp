//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SPLASHSCREEN_HPP
#define CPP_RTYPE_2019_SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/WindowState/WindowState.hpp"

namespace RType {
    using namespace RType;
    class SplashScreen {
    public:
        SplashScreen(sf::RenderWindow *app, WindowState *state);
        void run();
        ~SplashScreen();


    private:
        sf::Sprite _splash;
        sf::Texture *_currentTexture;
        sf::Clock *_clock;
        sf::RenderWindow *_app;
        bool _done;
        int _currentFrame;
        int _lastFrame;
        WindowState *_windowState;
    };
}


#endif //CPP_RTYPE_2019_SPLASHSCREEN_HPP
