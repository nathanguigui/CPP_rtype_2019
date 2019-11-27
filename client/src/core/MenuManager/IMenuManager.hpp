//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_IMENUMANAGER_HPP
#define CPP_RTYPE_2019_IMENUMANAGER_HPP

#include <client/src/core/TcpNetwork/TcpNetwork.hpp>
#include "client/src/core/WindowState/WindowState.hpp"

namespace RType {
    class IMenuManager {
    public:
        /// Switch menu in state & event manager
        virtual void switchMenu(MenuType menuType) = 0;

        /// Send Tcp commands
        virtual void sendTcpCommand(TcpNetwork::Commands) = 0;

        /// Set Lobby code from child menu
        virtual void setLobbyCode(std::string *code) = 0;
    };
}

#endif //CPP_RTYPE_2019_IMENUMANAGER_HPP
