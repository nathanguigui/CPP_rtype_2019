//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_ISCENEMANAGER_HPP
#define CPP_RTYPE_2019_ISCENEMANAGER_HPP

#include <string>
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

        enum EntityType {
            PLAYER,
            MONSTER,
            BULLET,
            POWERUP
        };

        virtual void updateMap(std::string mapId, std::string mapPosX) = 0;

        /// Update Player Alive
        virtual void updatePlayer(std::string uuid, std::string name, PlayerStatus status, int score, int life,
                int attackSpeed, int posX, int posY, ForcePodLevel forcePodLevel) = 0;

        /// Update player Dead
        virtual void updatePlayer(std::string uuid, std::string name, PlayerStatus status, int score) = 0;



    private:
    };
}

#endif //CPP_RTYPE_2019_ISCENEMANAGER_HPP
