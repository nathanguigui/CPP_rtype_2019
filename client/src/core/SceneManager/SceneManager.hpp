//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_SCENEMANAGER_HPP
#define CPP_RTYPE_2019_SCENEMANAGER_HPP

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <client/src/core/WindowManager/IWindowManager.hpp>
#include "client/src/core/Scene/Scene.hpp"
#include "client/src/core/Event/Event.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"
#include <client/src/game/UdpResponse/PlayerResponse/PlayerResponse.hpp>
#include "client/src/core/Settings/Settings.hpp"
#include "ISceneManager.hpp"

namespace RType {
    using namespace RType;
    class SceneManager: public ISceneManager {
    public:
        SceneManager(sf::RenderWindow *app, Event *eventManager, IWindowManager *parent);

        SceneManager(std::string *currentScene, sf::RenderWindow *app, Event *eventManager, Scene *scene);

        virtual ~SceneManager();

        void drawCurrentScene();

        void addSetCurrentScene(std::string *currentScene, Scene *scene, bool thiefEvent);

        void updateMap(std::string mapId, std::string mapPosX) override;

        void updatePlayer(PlayerResponse *response);

        void updateEntity(IUdpResponse *udpResponse) override;

    private:
        std::map<std::string, Scene*> _scenes;
        std::string *_currentScene;
        sf::RenderWindow *_app;
        Event *_eventManager;
        IWindowManager *_parent;
    };
}


#endif //CPP_RTYPE_2019_SCENEMANAGER_HPP
