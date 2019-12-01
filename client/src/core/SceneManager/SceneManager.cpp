//
// Created by guigui on 11/14/19.
//

#include "SceneManager.hpp"

RType::SceneManager::SceneManager(std::string *currentScene, sf::RenderWindow *app, Event *eventManager, Scene *scene)
        : _currentScene(currentScene), _app(app), _eventManager(eventManager) {
    this->_scenes.insert(std::pair<std::string, Scene*>(*currentScene, scene));
    this->_eventManager->addEventableObject((EventableObject*)scene);
}

RType::SceneManager::SceneManager(sf::RenderWindow *app, RType::Event *eventManager) : _app(app),
                                                                                       _eventManager(eventManager) {}

void RType::SceneManager::addSetCurrentScene(std::string *currentScene, Scene *scene, bool thiefEvent) {
    this->_currentScene = currentScene;
    this->_scenes.insert(std::pair<std::string, Scene*>(*currentScene, scene));
    if (thiefEvent)
        this->_eventManager->clearEventableObject();
    this->_eventManager->addEventableObject((EventableObject*)scene);
}

RType::SceneManager::~SceneManager() {

}

void RType::SceneManager::drawCurrentScene() {
    this->_scenes[*this->_currentScene]->draw();
}

void RType::SceneManager::updateMap(std::string mapId, std::string mapPosX) {
    // TODO handle update map
    std::cout << "update map pos to " << mapId << " pos: " << mapPosX << "\r\n";
}

void RType::SceneManager::updatePlayer(std::string uuid, std::string name, RType::ISceneManager::PlayerStatus status,
                                       int score, int life, int attackSpeed, int posX, int posY,
                                       RType::ISceneManager::ForcePodLevel forcePodLevel) {
    this->_scenes[*this->_currentScene]->updateCurrentPlayer(uuid, name, status, score, life, attackSpeed, posX, posY, forcePodLevel);
}

void RType::SceneManager::updatePlayer(std::string uuid, std::string name, RType::ISceneManager::PlayerStatus status,
                                       int score) {
    this->_scenes[*this->_currentScene]->updateCurrentPlayer(uuid, name, status, score);
}
