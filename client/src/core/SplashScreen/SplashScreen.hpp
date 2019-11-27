//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SPLASHSCREEN_HPP
#define CPP_RTYPE_2019_SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"

#include "../../game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet1/SuperBullet1.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet2/SuperBullet2.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet3/SuperBullet3.h"
#include "../../game/Bullets/BulletsShoot/MasterBullet/MasterBullet.h"
#include "../../game/Bullets/BulletsShoot/SimpleBomb/SimpleBomb.h"

#include "../../game/Bullets/BulletTouch/SimpleKill/SimpleKill.h"
#include "../../game/Bullets/BulletTouch/SimpleExplosion/SimpleExplosion.h"
#include "../../game/Bullets/BulletTouch/SuperTouch/SuperTouch.h"
#include "../../game/Bullets/BulletTouch/SimpleTouch/SimpleTouch.h"


namespace RType {
    using namespace RType;
    class SplashScreen: public CoreObject {
    public:
        SplashScreen(sf::RenderWindow *app, WindowState *state);
        void run();
        ~SplashScreen();


    private:
        RType::SuperBullet1 *super1;
        RType::SuperBullet2 *super2;
        RType::SuperBullet3 *super3;
        RType::SimpleBullet *bullet;
        RType::MasterBullet *master;
        RType::SimpleBomb *bomb;

        RType::SimpleKill *kill;
        RType::SimpleExplosion *boum;
        RType::SuperTouch *touch;
        RType::SimpleTouch *simpleTouch;

        sf::SoundBuffer _buffer;
        sf::Sound _sound;

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
