//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SCENE_HPP
#define CPP_RTYPE_2019_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <client/src/core/SceneManager/ISceneManager.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"
#include "client/src/core/EventableObject/EventableObject.hpp"
#include "client/src/core/EventableSceneObject/EventableSceneObject.hpp"
#include "client/src/core/Player/Player.hpp"
#include "IScene.hpp"

namespace RType {
    using namespace RType;
    class Scene: public IScene, public EventableObject {
    public:
        explicit Scene(sf::RenderWindow *app, IWindowManager *parent);
        virtual ~Scene();

        /// Relay Event to eventable objects
        void handleLeft() override;

        /// Relay Event to eventable objects
        void handleRight() override;

        /// Relay Event to eventable objects
        void handleUp() override;

        /// Relay Event to eventable objects
        void handleDown() override;

        /// Relay Event to eventable objects
        void handleEnter() override;

        /// Relay Event to eventable objects
        void handleKeyReleased() override;

        /// Tell all drawable element to draw
        void draw();

        /// Tell all drawable to destroy
        void destroy();

        /// Add player to drawable & eventable list
        void addPlayer(RType::Player::SkinColours skinColours);

        /// Add object to the list of rendered object
        void addSceneObject(SceneObject *object);

        /// Add or update object
        void updateObject(const std::string& uuid, SceneObject *object);

        /// Update current player
        void updateCurrentPlayer(const std::string& uuid, const std::string& name, ISceneManager::PlayerStatus status, int score, int life,
                int attackSpeed, int posX, int posY, ISceneManager::ForcePodLevel forcePodLevel);

        void updateCurrentPlayer(const std::string& uuid, const std::string& name, ISceneManager::PlayerStatus status, int score);

        /// Add object to get event from Scene
        void addEventableSceneObject(EventableSceneObject *eventableSceneObject);


        void updateEntity(IUdpResponse *udpResponse) override;
    private:

        /// App window
        sf::RenderWindow *_app;

        /// Drawable Objects
        std::map<std::string, SceneObject*> _sceneObjects;

        /// Eventable Objects
        std::vector<EventableSceneObject*> _eventableObjects;

        /// Current Player
        Player *_player{nullptr};

        IWindowManager *_parent;
    };
}


#endif //CPP_RTYPE_2019_SCENE_HPP
