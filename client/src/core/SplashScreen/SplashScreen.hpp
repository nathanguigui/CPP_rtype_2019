//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SPLASHSCREEN_HPP
#define CPP_RTYPE_2019_SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"
#include "../../game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h"
#include "../../game/Bullets/BulletTouch/SimpleKill/SimpleKill.h"

namespace RType {
    using namespace RType;
    class SplashScreen: public CoreObject {
    public:
        SplashScreen(sf::RenderWindow *app, WindowState *state);
        void run();
        ~SplashScreen();


    private:
        RType::SimpleBullet *bullet;
        RType::SimpleKill *kill;
        sf::Sprite *_splash;
        sf::Sprite *_background;
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_splashTexture;
        sf::Texture *_backgroundTexture;
        sf::Clock *_clock;
        sf::Clock *_splashClock;
        sf::RenderWindow *_app;
        bool _done;
        int _currentFrame;
        int _lastFrame;
        WindowState *_windowState;
    };
}


#endif //CPP_RTYPE_2019_SPLASHSCREEN_HPP
