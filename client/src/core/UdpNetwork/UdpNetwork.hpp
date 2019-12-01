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
#include <client/src/core/WindowManager/IWindowManager.hpp>
#include "client/src/core/SceneManager/ISceneManager.hpp"
#include "IUdpNetwork.hpp"

namespace RType {
    using namespace RType;

    class UdpNetwork : public IUdpNetwork {
    public:
        /// Default ctor
        UdpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                   Settings *settings, IWindowManager *parent);

        /// Default dtor
        virtual ~UdpNetwork();

        /// Wait for packet and parse it
        bool waitForPacket();

        /// Set current menu manager to send callback
        void setMenuManager(IMenuManager *menuManager);

        std::string *getDestIp() const;

        void setDestIp(std::string *destIp);

        unsigned short getDestPort() const;

        void setDestPort(unsigned short destPort) override;

        /// Send Data to socket
        void sendData(const std::string &data) override;

        void sayHello();

        void sayUsername();

        void update();

        void startGame();

        bool isNeedUpdate() const;

        void setNeedUpdate(bool needUpdate);

    private:

        /// Parse multiple packet
        void parseMultiplePacket(char *packet, std::size_t packetSize);

        /// Parse received packet
        void parsePacket(std::string packet);

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

        /// WindowManager
        IWindowManager *_parent;

        bool _needUpdate = false;

    };
}


#endif //CPP_RTYPE_2019_UDPNETWORK_HPP
