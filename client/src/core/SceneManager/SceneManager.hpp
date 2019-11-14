//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_SCENEMANAGER_HPP
#define CPP_RTYPE_2019_SCENEMANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include "client/src/core/Scene/Scene.hpp"
#include "client/src/core/Event/Event.hpp"

namespace RType {
    using namespace RType;
    class SceneManager {
    public:
        SceneManager(sf::RenderWindow *app, Event *eventManager);

        SceneManager(std::string *currentScene, sf::RenderWindow *app, Event *eventManager, Scene *scene);

        virtual ~SceneManager();

        void addSetCurrentScene(std::string *currentScene, Scene *scene, bool thiefEvent);

    private:
        std::map<std::string, Scene*> _scenes;
        std::string *_currentScene;
        sf::RenderWindow *_app;
        Event *_eventManager;
    };
}


#endif //CPP_RTYPE_2019_SCENEMANAGER_HPP
