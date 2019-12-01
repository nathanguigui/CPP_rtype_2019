//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_SCENEMANAGER_HPP
#define CPP_RTYPE_2019_SCENEMANAGER_HPP

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "client/src/core/Scene/Scene.hpp"
#include "client/src/core/Event/Event.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"
#include "ISceneManager.hpp"

namespace RType {
    using namespace RType;
    class SceneManager: public ISceneManager {
    public:
        SceneManager(sf::RenderWindow *app, Event *eventManager);

        SceneManager(std::string *currentScene, sf::RenderWindow *app, Event *eventManager, Scene *scene);

        virtual ~SceneManager();

        void drawCurrentScene();

        void addSetCurrentScene(std::string *currentScene, Scene *scene, bool thiefEvent);

        void updateMap(std::string mapId, std::string mapPosX) override;

        /// Update Player Alive
        void updatePlayer(std::string uuid, std::string name, PlayerStatus status, int score, int life,
                int attackSpeed, int posX, int posY, ISceneManager::ForcePodLevel forcePodLevel) override;

        /// Update player Dead
        void updatePlayer(std::string uuid, std::string name, ISceneManager::PlayerStatus status, int score) override;

    private:
        std::map<std::string, Scene*> _scenes;
        std::string *_currentScene;
        sf::RenderWindow *_app;
        Event *_eventManager;
    };
}


#endif //CPP_RTYPE_2019_SCENEMANAGER_HPP
