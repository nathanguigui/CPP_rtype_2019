//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SPLASHSCREEN_HPP
#define CPP_RTYPE_2019_SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>

namespace RType {
    class SplashScreen {
    public:
        explicit SplashScreen(sf::RenderWindow *app);
        void run();
        ~SplashScreen();

    private:
        sf::RenderWindow *_app;
    };
}


#endif //CPP_RTYPE_2019_SPLASHSCREEN_HPP
