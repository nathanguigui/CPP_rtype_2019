//
// Created by guigui on 12/1/19.
//

#include <cstring>
#include "MonsterResponse.hpp"

RType::MonsterResponse::MonsterResponse(std::string uuid, int posX, int posY, std::string type) : _uuid(
        uuid), _posX(posX), _posY(posY) {
    if (std::strncmp(type.c_str(), "0x620", 5) == 0)
        _type = MonsterResponse::ALPHA;
    if (std::strncmp(type.c_str(), "0x621", 5) == 0)
        _type = MonsterResponse::BETTA;
    if (std::strncmp(type.c_str(), "0x622", 5) == 0)
        _type = MonsterResponse::GAMMA;
    if (std::strncmp(type.c_str(), "0x623", 5) == 0)
        _type = MonsterResponse::DELTA;
}

const std::string &RType::MonsterResponse::getUuid() const {
    return _uuid;
}

RType::IUdpResponse::EntityType RType::MonsterResponse::getType() {
    return _entityType;
}

RType::MonsterResponse::MonsterType RType::MonsterResponse::getMonsterType() const {
    return _type;
}

int RType::MonsterResponse::getPosX() const {
    return _posX;
}

int RType::MonsterResponse::getPosY() const {
    return _posY;
}
