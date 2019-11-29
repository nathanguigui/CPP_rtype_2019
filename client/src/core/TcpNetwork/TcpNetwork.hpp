//
// Created by guigui on 11/25/19.
//

#ifndef CPP_RTYPE_2019_TCPNETWORK_HPP
#define CPP_RTYPE_2019_TCPNETWORK_HPP

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <client/src/core/Settings/Settings.hpp>
#include "client/src/core/core.hpp"
#include "client/src/core/Exception/Exception.hpp"
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/Loading/Loading.hpp"
#include "client/src/core/MenuManager/IMenuManager.hpp"
#include "client/src/core/TcpNetwork/ITcpNetwork.hpp"

namespace RType {
    using namespace RType;

    class TcpNetwork : public ITcpNetwork {
    public:
        /// Default ctor
        TcpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                   Loading *loading, Settings *settings);

        /// Default dtor
        virtual ~TcpNetwork();

        /// Connect SFML socket to destination
        void connect();

        /// Create a Lobby
        void createLobby(std::string *playerName);

        /// Join a Lobby
        void joinLobby(std::string *code, std::string *playerName);

        /// Set player ready
        void lobbyReady(std::string code, std::string playerName);

        /// Get Lobby infos
        void lobbyInfo(std::string code);

        /// Start Lobby
        void lobbyStart(std::string code);

        /// Wait for packet and parse it
        void waitForPacket();

        /// Set current menu manager to send callback
        void setMenuManager(IMenuManager *menuManager);

    private:
        /// Send Data to socket
        void sendData(const std::string& data);

        /// Parse multiple packet
        void parseMultiplePacket(char *packet, std::size_t packetSize);

        /// Parse received packet
        void parsePacket(std::string command);

        /// SFML app
        sf::RenderWindow *_app;

        /// Window State
        WindowState *_state;

        /// Destination IP
        std::string *_destIp;

        /// Destination Port
        const unsigned short _destPort;

        /// SFML Tcp socket
        sf::TcpSocket *_tcpSocket;

        /// SFML socket status
        sf::Socket::Status _status{};

        /// Loading Screen
        Loading *_loadingScreen;

        /// Settings
        Settings *_settings;

        /// Window menu manager
        IMenuManager *_menuManager = nullptr;

    };
}


#endif //CPP_RTYPE_2019_TCPNETWORK_HPP
