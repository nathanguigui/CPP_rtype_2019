//
// Created by guigui on 11/25/19.
//

#ifndef CPP_RTYPE_2019_TCPNETWORK_HPP
#define CPP_RTYPE_2019_TCPNETWORK_HPP

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "client/src/core/core.hpp"
#include "client/src/core/Exception/Exception.hpp"
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/Loading/Loading.hpp"

namespace RType {
    using namespace RType;

    class TcpNetwork {
    public:
        /// Default ctor
        TcpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                   Loading *loading);

        /// Default dtor
        virtual ~TcpNetwork();

        /// Connect SFML socket to destination
        void connect();

        /// Create a Lobby
        void createLobby();

    private:
        /// Send Data to socket
        void sendData(const std::string& data);

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
    };
}


#endif //CPP_RTYPE_2019_TCPNETWORK_HPP
