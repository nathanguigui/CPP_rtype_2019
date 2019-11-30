//
// Created by guigui on 11/30/19.
//

#ifndef CPP_RTYPE_2019_UDPNETWORK_HPP
#define CPP_RTYPE_2019_UDPNETWORK_HPP


#include <string>
#include <SFML/Graphics.hpp>
#include <client/src/core/WindowState/WindowState.hpp>
#include <SFML/Network/UdpSocket.hpp>
#include <client/src/core/Settings/Settings.hpp>
#include <client/src/core/MenuManager/IMenuManager.hpp>
#include <SFML/Network/Packet.hpp>
#include <client/src/core/core.hpp>
#include <SFML/Network/SocketSelector.hpp>

namespace RType {
    using namespace RType;

    class UdpNetwork : public CoreObject {
    public:
        /// Default ctor
        UdpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, const unsigned short destPort,
                   Settings *settings);

        /// Default dtor
        virtual ~UdpNetwork();

        /// Wait for packet and parse it
        bool waitForPacket();

        /// Set current menu manager to send callback
        void setMenuManager(IMenuManager *menuManager);

        std::string *getDestIp() const;

        void setDestIp(std::string *destIp);

        unsigned short getDestPort() const;

        void setDestPort(unsigned short destPort);

    private:
        /// Send Data to socket
        void sendData(const std::string &data);

        /// Parse multiple packet
        void parseMultiplePacket(char *packet, std::size_t packetSize);

        /// Parse received packet
        void parsePacket(char *packet);

        /// SFML app
        sf::RenderWindow *_app;

        /// Window State
        WindowState *_state;

        /// Destination IP
        std::string *_destIp;

        /// Destination port
        unsigned short _destPort;

        /// SFML Udp socket
        sf::UdpSocket *_udpSocket;

        /// SFML socket status
        sf::Socket::Status _status{};

        /// Settings
        Settings *_settings;

        /// Window menu manager
        IMenuManager *_menuManager = nullptr;


    };
}


#endif //CPP_RTYPE_2019_UDPNETWORK_HPP
