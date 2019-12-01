//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_ISCENEMANAGER_HPP
#define CPP_RTYPE_2019_ISCENEMANAGER_HPP

#include <string>
#include <client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp>
#include "client/src/core/CoreObject/CoreObject.hpp"

namespace RType {
    class ISceneManager : public CoreObject {
    public:

        /// Update game data from UdpNetwork
        //void updateData();

        enum PlayerStatus {
            ALIVE,
            DEAD
        };

        enum ForcePodLevel {
            LOW_POWER,
            MEDIUM_POWER,
            HIGH_POWER
        };

        virtual void updateMap(std::string mapId, std::string mapPosX) = 0;

        virtual void updateEntity(IUdpResponse *udpResponse) = 0;

    private:
    };
}

#endif //CPP_RTYPE_2019_ISCENEMANAGER_HPP
