//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_IMENUMANAGER_HPP
#define CPP_RTYPE_2019_IMENUMANAGER_HPP

#include "client/src/core/WindowState/WindowState.hpp"

namespace RType {
    class IMenuManager {
    public:
        virtual void switchMenu(MenuType menuType) = 0;
    };
}

#endif //CPP_RTYPE_2019_IMENUMANAGER_HPP
