//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SCENEOBJECT_HPP
#define CPP_RTYPE_2019_SCENEOBJECT_HPP


namespace RType {
    class SceneObject {
    public:
        virtual void draw() = 0;
        virtual void destroy() = 0;
    };
}


#endif //CPP_RTYPE_2019_SCENEOBJECT_HPP
