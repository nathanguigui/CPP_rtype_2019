//
// Created by guigui on 12/1/19.
//

#include "PlayerResponse.hpp"

RType::PlayerResponse::PlayerResponse(int score, int life, int attackSpeed, int posX, int posY, std::string forcePodLevel,
                                      ISceneManager::PlayerStatus playerStatus, std::string name, std::string uuid)
        : _score(score), _life(life),_attackSpeed(attackSpeed),_posX(posX), _posY(posY),_playerStatus(playerStatus), _uuid(uuid), _name(name){
    if (std::strncmp(forcePodLevel.c_str(), "0x615", 5) == 0)
        _forcePodLevel = ISceneManager::LOW_POWER;
    if (std::strncmp(forcePodLevel.c_str(), "0x616", 5) == 0)
        _forcePodLevel = ISceneManager::MEDIUM_POWER;
    if (std::strncmp(forcePodLevel.c_str(), "0x617", 5) == 0)
        _forcePodLevel = ISceneManager::HIGH_POWER;
}

RType::IUdpResponse::EntityType RType::PlayerResponse::getType() {
    return _type;
}

std::string RType::PlayerResponse::getUuid() const {
    return _uuid;
}

std::string RType::PlayerResponse::getName() const {
    return _name;
}

int RType::PlayerResponse::getScore() const {
    return _score;
}

int RType::PlayerResponse::getLife() const {
    return _life;
}

int RType::PlayerResponse::getAttackSpeed() const {
    return _attackSpeed;
}

int RType::PlayerResponse::getPosX() const {
    return _posX;
}

int RType::PlayerResponse::getPosY() const {
    return _posY;
}

RType::ISceneManager::ForcePodLevel RType::PlayerResponse::getForcePodLevel() const {
    return _forcePodLevel;
}

RType::ISceneManager::PlayerStatus RType::PlayerResponse::getPlayerStatus() const {
    return _playerStatus;
}

RType::PlayerResponse::PlayerResponse(int score, RType::ISceneManager::PlayerStatus playerStatus, std::string name,
                                      std::string uuid) : _score(score), _playerStatus(playerStatus), _uuid(uuid), _name(name) {

}
