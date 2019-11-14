//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SCENE_HPP
#define CPP_RTYPE_2019_SCENE_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"
#include "client/src/core/EventableObject/EventableObject.hpp"
#include "client/src/core/EventableSceneObject/EventableSceneObject.hpp"

namespace RType {
    using namespace RType;
    class Scene: EventableObject {
    public:
        explicit Scene(sf::RenderWindow *app);
        virtual ~Scene();
        void draw();
        void addSceneObject(SceneObject *object);
        void addEventableSceneObject(EventableSceneObject *eventableSceneObject);
        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
        void destroy();

    private:
        sf::RenderWindow *_app;
        std::vector<SceneObject*> _objects;
        std::vector<EventableSceneObject*> _eventableObjects;
    };
}


#endif //CPP_RTYPE_2019_SCENE_HPP
