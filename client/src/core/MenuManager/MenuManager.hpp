//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_MENUMANAGER_HPP
#define CPP_RTYPE_2019_MENUMANAGER_HPP


#include <client/src/core/Menus/Lobby/Lobby.hpp>
#include "client/src/core/Settings/Settings.hpp"
#include "client/src/core/Menus/MainMenu/MainMenu.hpp"
#include "client/src/core/Menus/JoinLobby/JoinLobby.hpp"
#include "client/src/core/TcpNetwork/TcpNetwork.hpp"
#include "client/src/core/Sounds/MenuMusic/MenuMusic.h"
#include "IMenuManager.hpp"

namespace RType {
    class MenuManager : public IMenuManager {
    public:
        /// Default ctor
        MenuManager(WindowState *state, Event *event, sf::RenderWindow *app, TcpNetwork *network, Settings *settings);

        /// Default dtor
        virtual ~MenuManager();

        /// Draw the apropriate menu
        void draw();

        /// Switch menu
        void switchMenu(MenuType menuType) override;

        /// Send Tcp commands
        void sendTcpCommand(TcpNetwork::Commands commands) override;

        /// Set Lobby code from child menu
        void setLobbyCode(std::string *code) override;

    private:
        /// Background music
        MenuMusic *_menumusic;

        /// Main menu
        MainMenu *_mainMenu;

        /// Join game menu
        JoinLobby *_joinLobby;

        /// Lobby menu
        Lobby *_lobbyMenu;

        /// window State
        WindowState *_state;

        /// Window Event
        Event *_event;

        /// Window Settings
        Settings *_settings;

        /// SFML app
        sf::RenderWindow *_app;

        /// Lobby Network
        TcpNetwork *_network;
    };
}


#endif //CPP_RTYPE_2019_MENUMANAGER_HPP
