//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_ANIMATESPRITE_HPP
#define CPP_RTYPE_2019_ANIMATESPRITE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"

/// bullets sprites
#include "../../game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet1/SuperBullet1.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet2/SuperBullet2.h"
#include "../../game/Bullets/BulletsShoot/SuperBullet3/SuperBullet3.h"
#include "../../game/Bullets/BulletsShoot/MasterBullet/MasterBullet.h"
#include "../../game/Bullets/BulletsShoot/SimpleBomb/SimpleBomb.h"

/// kill or touch sprites
#include "../../game/Bullets/BulletTouch/SimpleKill/SimpleKill.h"
#include "../../game/Bullets/BulletTouch/SimpleExplosion/SimpleExplosion.h"
#include "../../game/Bullets/BulletTouch/SuperTouch/SuperTouch.h"
#include "../../game/Bullets/BulletTouch/SimpleTouch/SimpleTouch.h"

/// enemies sprites
#include "../../game/enemies/LittleRed/LittleRed.h"

namespace RType {
    using namespace RType;
    class AnimateSprite: public CoreObject {
    public:
        AnimateSprite(sf::RenderWindow *app, WindowState *state);
        void run(std::string type);
        ~AnimateSprite();


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

        RType::LittleRed *redenemy;

        sf::SoundBuffer _buffer;
        sf::Sound _sound;

        sf::Sprite *_splash;

        sf::IntRect *_rectSourceSprite;

        sf::Texture *_splashTexture;

        sf::Clock *_splashClock;

        sf::RenderWindow *_app;
        WindowState *_windowState;

        std::map<std::string, ISprite*> sprites;
    };
}


#endif //CPP_RTYPE_2019_SPLASHSCREEN_HPP
