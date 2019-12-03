//
// Created by guigui on 11/13/19.
//

#include <client/src/core/WindowManager/IWindowManager.hpp>
#include <client/src/game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h>
#include "Scene.hpp"

RType::Scene::Scene(sf::RenderWindow *app, IWindowManager *parent): _app(app), _parent(parent) {
    this->_background = new sf::Sprite();
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile("assets/MainMenu/logo.png");
    this->_background->setTexture(*this->_texture);
    this->_background->setPosition(0.0, 1.0);
}

RType::Scene::~Scene() = default;

void RType::Scene::draw() {
    for (auto & _object : this->_sceneObjects)
        _object.second->draw();
}

void RType::Scene::addSceneObject(SceneObject *object) {
    std::string tmp = "toto";
    this->_sceneObjects.insert({tmp, object});
}

void RType::Scene::handleLeft() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleLeft();
}

void RType::Scene::handleRight() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleRight();
}

void RType::Scene::handleUp() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleUp();
}

void RType::Scene::handleDown() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleDown();
}

void RType::Scene::handleEnter() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleEnter();
}

void RType::Scene::handleKeyReleased() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleKeyReleased();
}

void RType::Scene::addEventableSceneObject(RType::EventableSceneObject *eventableSceneObject) {
    this->_eventableObjects.push_back(eventableSceneObject);
}

void RType::Scene::destroy() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->destroy();
    for (auto & _object : this->_sceneObjects) _object.second->destroy();
}

void RType::Scene::addPlayer(RType::Player::SkinColours skinColours) {
    if (this->_player)
        return;
    this->_player = new Player(this->_app, this, skinColours);
    this->_player->setUdpNetwork((UdpNetwork*)this->_parent->getUdpNetwork());
    this->addEventableSceneObject((EventableSceneObject*)this->_player);
    this->addSceneObject((SceneObject*)this->_player);
}

void RType::Scene::updateObject(const std::string& uuid, RType::SceneObject *object) {
    if (this->_sceneObjects.find(uuid) == this->_sceneObjects.end()) {
        this->_sceneObjects.insert({uuid, object});
    }
}

void RType::Scene::updateCurrentPlayer(const std::string& uuid, const std::string& name, RType::ISceneManager::PlayerStatus status,
                                       int score, int life, int attackSpeed, int posX, int posY,
                                       RType::ISceneManager::ForcePodLevel forcePodLevel) {
    this->_player->setPosition(sf::Vector2f(posX/4, posY/4));
}

void RType::Scene::updateCurrentPlayer(const std::string& uuid, const std::string& name, RType::ISceneManager::PlayerStatus status,
                                       int score) {

}

void RType::Scene::updateEntity(RType::IUdpResponse *udpResponse) {
    /// Entity exist
    if (this->_sceneObjects.find(udpResponse->getUuid()) != this->_sceneObjects.end())
        this->_sceneObjects[udpResponse->getUuid()]->setPosition(sf::Vector2f(udpResponse->getPosX() / 4,udpResponse->getPosY() / 4));
    else { /// Entity doesn't exist
        SimpleBullet *bull = nullptr;
        std::cout << "creating entity\r\n";
        switch (udpResponse->getType()) {
            case IUdpResponse::PLAYER:
                break;
            case IUdpResponse::MONSTER:
                break;
            case IUdpResponse::BULLET:
                std::cout << "creating bullet\r\n";
                bull = new SimpleBullet(this->_app);
                bull->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                this->_sceneObjects.insert({udpResponse->getUuid(), bull});
                break;
            case IUdpResponse::POWERUP:
                break;
        }
    }
}
