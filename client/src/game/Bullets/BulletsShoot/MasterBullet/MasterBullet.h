//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_MASTERBULLET_H
#define CPP_RTYPE_2019_MASTERBULLET_H

#include <SFML/Graphics.hpp>
#include <client/src/core/SceneObject/SceneObject.hpp>
#include "../../../AnimateSprite/ISprite.hpp"

namespace RType {
    using namespace RType;
    class MasterBullet : public SceneObject {
    public:
        explicit MasterBullet(sf::RenderWindow *app);
        ~MasterBullet();

        void setPosition(sf::Vector2f pos) override;

        sf::Vector2f getPosition() override {return _sprite->getPosition();};
        void run();
        void draw() override;
        void destroy() override;

    private:
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_bulletTexture;
        sf::RenderWindow *_app;
        sf::Sprite *_sprite;
        int step;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEBULLET_H
