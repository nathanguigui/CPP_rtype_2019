//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_IUDPRESPONSE_HPP
#define CPP_RTYPE_2019_IUDPRESPONSE_HPP

#include <string>
#include "client/src/core/CoreObject/CoreObject.hpp"

namespace RType {
    using namespace RType;

    class IUdpResponse {
    public:
        enum EntityType {
            PLAYER,
            MONSTER,
            BULLET,
            POWERUP
        };

        virtual EntityType getType() = 0;

    };
}

#endif //CPP_RTYPE_2019_IUDPRESPONSE_HPP
