//
// Created by guigui on 11/13/19.
//

#include "Scene.hpp"

RType::Scene::Scene(sf::RenderWindow *app): _app(app) {

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
