//
// Created by guigui on 12/1/19.
//

#include <cstring>
#include "BulletResponse.hpp"

RType::BulletResponse::BulletResponse(std::string uuid, int posX, int posY, std::string type) : _uuid(uuid), _posX(posX),
                                                                                                _posY(posY) {
    if (std::strncmp(type.c_str(), "0x630", 5) == 0)
        _type = BulletResponse::BULL_ONE;
    if (std::strncmp(type.c_str(), "0x631", 5) == 0)
        _type = BulletResponse::BULL_TWO;
    if (std::strncmp(type.c_str(), "0x632", 5) == 0)
        _type = BulletResponse::BULL_THREE;
    if (std::strncmp(type.c_str(), "0x635", 5) == 0)
        _type = BulletResponse::BULL_FOUR;
    if (std::strncmp(type.c_str(), "0x636", 5) == 0)
        _type = BulletResponse::BULL_FIVE;
    if (std::strncmp(type.c_str(), "0x637", 5) == 0)
        _type = BulletResponse::BULL_SIX;
    if (std::strncmp(type.c_str(), "0x638", 5) == 0)
        _type = BulletResponse::BULL_SEVEN;
}

std::string RType::BulletResponse::getUuid() const {
    return _uuid;
}

RType::IUdpResponse::EntityType RType::BulletResponse::getType() {
    return _entityType;
}

RType::BulletResponse::BulletType RType::BulletResponse::getBulletType() const {
    return _type;
}

int RType::BulletResponse::getPosX() const {
    return _posX;
}

int RType::BulletResponse::getPosY() const {
    return _posY;
}
