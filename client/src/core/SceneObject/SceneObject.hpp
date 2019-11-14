//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SCENEOBJECT_HPP
#define CPP_RTYPE_2019_SCENEOBJECT_HPP


#include <SFML/System.hpp>

namespace RType {
    class SceneObject {
    public:
        virtual void draw() = 0;
        virtual void destroy() = 0;
        virtual void setPosition(sf::Vector2f newPos) = 0;
        virtual sf::Vector2f getPosition() = 0;
    };
}


#endif //CPP_RTYPE_2019_SCENEOBJECT_HPP
