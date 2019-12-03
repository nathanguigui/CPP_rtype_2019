//
// Created by guigui on 12/1/19.
//

#include <cstring>
#include "PowerupResponse.hpp"

RType::PowerupResponse::PowerupResponse(std::string uuid, int posX, int posY, std::string powType)
        : _uuid(uuid), _posX(posX),
          _posY(posY) {
    if (std::strncmp(powType.c_str(), "0x640", 5) == 0)
        _type = PowerupResponse::HEALTH_POW;
    if (std::strncmp(powType.c_str(), "0x641", 5) == 0)
        _type = PowerupResponse::ATTACK_POW;
}

std::string RType::PowerupResponse::getUuid() const {
    return _uuid;
}

RType::PowerupResponse::PowerupType RType::PowerupResponse::getType1() const {
    return _type;
}

int RType::PowerupResponse::getPosX() const {
    return _posX;
}

int RType::PowerupResponse::getPosY() const {
    return _posY;
}

RType::IUdpResponse::EntityType RType::PowerupResponse::getType() {
    return _entityType;
}
