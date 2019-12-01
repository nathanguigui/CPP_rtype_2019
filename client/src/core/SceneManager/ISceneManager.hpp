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

        virtual void updateMap(std::string mapId, std::string mapPosX) = 0;



    private:
    };
}

#endif //CPP_RTYPE_2019_ISCENEMANAGER_HPP
