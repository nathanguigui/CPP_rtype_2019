//
// Created by guigui on 11/15/19.
//

#ifndef CPP_RTYPE_2019_POWERENUM_HPP
#define CPP_RTYPE_2019_POWERENUM_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/SceneObject/SceneObject.hpp"
#include "client/src/core/PowerUp/PowerUp.hpp"
#include "client/src/core/core.hpp"

namespace RType {
    class PowerEnum {

    public:
        enum PowerSpeed {
            SLOW,
            NORMAL,
            FAST,
        };
        enum PowerDirection {
            UP,
            UP_LEFT,
            LEFT,
            DOWN_LEFT,
            DOWN,
            DOWN_RIGHT,
            RIGHT,
            UP_RIGHT
        };
    };
}

#endif //CPP_RTYPE_2019_POWERENUM_HPP
