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
        explicit SplashScreen(sf::RenderWindow *app);
        void run();
        ~SplashScreen();


    private:
        sf::Sprite _splash;
        sf::Texture *_currentTexture;
        sf::RenderWindow *_app;
        bool _done;
        int _currentFrame;
        int _lastFrame;
        WindowState *_windowState;
    };
}


#endif //CPP_RTYPE_2019_SPLASHSCREEN_HPP
