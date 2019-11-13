//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SCENE_HPP
#define CPP_RTYPE_2019_SCENE_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"

namespace RType {
    using namespace RType;
    class Scene {
    public:
        explicit Scene(sf::RenderWindow *app);
        virtual ~Scene();
        void draw();
        void addSceneObject(SceneObject *object);

    private:
        sf::RenderWindow *_app;
        std::vector<SceneObject*> _objects;
    };
}


#endif //CPP_RTYPE_2019_SCENE_HPP
