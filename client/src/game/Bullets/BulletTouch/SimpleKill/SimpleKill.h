//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_SIMPLEKILL_H
#define CPP_RTYPE_2019_SIMPLEKILL_H

#include <SFML/Graphics.hpp>
#include <client/src/core/SceneObject/SceneObject.hpp>


namespace RType {
    using namespace RType;
    class SimpleKill : public SceneObject {
    public:
        explicit SimpleKill(sf::RenderWindow *app);
        ~SimpleKill();
        void setPosition(sf::Vector2f pos) override;
        sf::Vector2f getPosition() override {return _sprite->getPosition();};
        void run();
        void draw() override;
        void destroy() override;

    private:
        int step;
        sf::IntRect *_rectSourceSprite;
        sf::Texture *_killTexture;
        sf::RenderWindow *_app;
        sf::Sprite *_sprite;
    };
}


#endif //CPP_RTYPE_2019_SIMPLEKILL_H
