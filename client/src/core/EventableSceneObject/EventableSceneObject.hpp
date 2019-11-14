//
// Created by guigui on 11/14/19.
//

#ifndef CPP_RTYPE_2019_EVENTABLESCENEOBJECT_HPP
#define CPP_RTYPE_2019_EVENTABLESCENEOBJECT_HPP

#include "client/src/core/EventableObject/EventableObject.hpp"
#include "client/src/core/SceneObject/SceneObject.hpp"

namespace RType {
    class EventableSceneObject: public SceneObject, public EventableObject {
    public:
        EventableSceneObject();
        ~EventableSceneObject();
        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
    };
}


#endif //CPP_RTYPE_2019_EVENTABLESCENEOBJECT_HPP
