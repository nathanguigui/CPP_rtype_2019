//
// Created by guigui on 11/14/19.
//

#include <client/src/core/Gui/Tools.hpp>
#include <boost/algorithm/string.hpp>
#include "SceneManager.hpp"

RType::SceneManager::SceneManager(std::string *currentScene, sf::RenderWindow *app, Event *eventManager, Scene *scene)
        : _currentScene(currentScene), _app(app), _eventManager(eventManager) {
    this->_scenes.insert(std::pair<std::string, Scene*>(*currentScene, scene));
    this->_eventManager->addEventableObject((EventableObject*)scene);
}

RType::SceneManager::SceneManager(sf::RenderWindow *app, Event *eventManager, IWindowManager *parent) : _app(app),
                                                                                                        _eventManager(eventManager),
                                                                                                        _parent(parent) {}

void RType::SceneManager::addSetCurrentScene(std::string *currentScene, Scene *scene, bool thiefEvent) {
    this->_currentScene = currentScene;
    this->_scenes.insert(std::pair<std::string, Scene*>(*currentScene, scene));
    if (thiefEvent)
        this->_eventManager->clearEventableObject();
    this->_eventManager->addEventableObject((EventableObject*)scene);
}

RType::SceneManager::~SceneManager() = default;

void RType::SceneManager::drawCurrentScene() {
    this->_scenes[*this->_currentScene]->draw();
}

void RType::SceneManager::updateMap(std::string mapId, std::string mapPosX) {
    // TODO handle update map
    std::cout << "update map pos to " << mapId << " pos: " << mapPosX << "\r\n";
}

void RType::SceneManager::updateEntity(RType::IUdpResponse *udpResponse) {
    if (udpResponse->getType() == IUdpResponse::EntityType::PLAYER)
        this->updatePlayer((PlayerResponse*)udpResponse);
}

void RType::SceneManager::updatePlayer(RType::PlayerResponse *response) {
    auto playerName = ((Settings*)this->_parent->getSettings())->getPlayerName();
    auto playerResponseName = hexToString(response->getName());
    playerResponseName.erase(std::remove(playerResponseName.begin(), playerResponseName.end(), '\r'), playerResponseName.end());
    playerResponseName.erase(std::remove(playerResponseName.begin(), playerResponseName.end(), '\n'), playerResponseName.end());
    /// Update only current player
    if (std::strncmp(playerName->c_str(), playerResponseName.c_str(), playerName->size()) == 0) {
        if (response->getPlayerStatus() == ISceneManager::PlayerStatus::DEAD)
            this->_scenes[*this->_currentScene]->updateCurrentPlayer(response->getUuid(), response->getName(), response->getPlayerStatus(), response->getScore());
        else if (response->getPlayerStatus() == ISceneManager::PlayerStatus::ALIVE)
            this->_scenes[*this->_currentScene]->updateCurrentPlayer(response->getUuid(), response->getName(), response->getPlayerStatus(), response->getScore(),
                    response->getLife(), response->getAttackSpeed(), response->getPosX(), response->getPosY(), response->getForcePodLevel());
    }
}
