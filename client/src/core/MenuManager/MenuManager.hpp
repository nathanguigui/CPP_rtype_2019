//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_MENUMANAGER_HPP
#define CPP_RTYPE_2019_MENUMANAGER_HPP


#include <client/src/game/Menus/Lobby/Lobby.hpp>
#include <client/src/core/LoadScreen/LoadScreen.hpp>
#include <client/src/game/Menus/SettingsMenu/SettingsMenu.hpp>
#include "client/src/core/Settings/Settings.hpp"
#include "client/src/game/Menus/MainMenu/MainMenu.hpp"
#include "client/src/game/Menus/JoinLobby/JoinLobby.hpp"
#include "client/src/core/TcpNetwork/TcpNetwork.hpp"
#include "client/src/core/SoundManager/SoundManager.hpp"
#include "IMenuManager.hpp"

namespace RType {
    class MenuManager : public IMenuManager {
    public:
        /// Default ctor
        MenuManager(WindowState *state, Event *event, sf::RenderWindow *app, TcpNetwork *network,
                    Settings *settings, LoadScreen *loadScreen);

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

        /// SoundManager
        SoundManager *_soundmanager;

        /// Main menu
        MainMenu *_mainMenu;

        /// Join game menu
        JoinLobby *_joinLobby;

        /// Lobby menu
        Lobby *_lobbyMenu;

        /// Settings menu
        SettingsMenu *_settingsMenu;

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

        /// Load Screen
        LoadScreen *_loadScreen;
    };
}


#endif //CPP_RTYPE_2019_MENUMANAGER_HPP
