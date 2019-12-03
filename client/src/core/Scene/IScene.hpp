//
// Created by guigui on 11/15/19.
//

#ifndef CPP_RTYPE_2019_ISCENE_HPP
#define CPP_RTYPE_2019_ISCENE_HPP

#include <client/src/core/SceneObject/SceneObject.hpp>
#include <client/src/core/EventableSceneObject/EventableSceneObject.hpp>
#include "client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp"

namespace RType {
    using namespace RType;
    class IScene {
    public:
        /// Add object to the list of rendered object
        virtual void addSceneObject(SceneObject *object) = 0;

        /// Add object to get event from Scene
        virtual void addEventableSceneObject(EventableSceneObject *eventableSceneObject) = 0;

        virtual void updateEntity(IUdpResponse *udpResponse) = 0;
    };
}

#endif //CPP_RTYPE_2019_ISCENE_HPP
