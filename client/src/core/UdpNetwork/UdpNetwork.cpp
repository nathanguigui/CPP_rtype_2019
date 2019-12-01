//
// Created by guigui on 11/30/19.
//

#include <sstream>
#include <client/src/core/WindowManager/IWindowManager.hpp>
#include "UdpNetwork.hpp"

RType::UdpNetwork::UdpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                              Settings *settings, IWindowManager *parent) : _app(app), _state(state),
                                                                                          _destIp(destIp),
                                                                                          _destPort(destPort),
                                                                                          _settings(settings),
                                                                                          _parent(parent) {
    this->_udpSocket = new sf::UdpSocket();
}

RType::UdpNetwork::~UdpNetwork() = default;

bool RType::UdpNetwork::waitForPacket() {
    sf::SocketSelector aSelector;
    sf::IpAddress ipAddress(*this->_destIp);
    sf::Packet packet;
    aSelector.add(*this->_udpSocket);
    if (aSelector.wait(sf::milliseconds(UDP_SOCKET_SELECTOR_TIMEOUT))) {
        if (aSelector.isReady(*this->_udpSocket)) {
            std::cout << "packet received on udp\r\n";
            this->_udpSocket->receive(packet, ipAddress, this->_destPort);
            this->parseMultiplePacket((char *)packet.getData(), packet.getDataSize());
        }
    }
}

void RType::UdpNetwork::setMenuManager(RType::IMenuManager *menuManager) {
    _menuManager = menuManager;
}

void RType::UdpNetwork::sendData(const std::string &data) {
    sf::IpAddress destIp(this->_destIp->c_str());
    if (this->_udpSocket->send(data.c_str(), data.size(), destIp, this->_destPort) != sf::Socket::Done)
        std::cout << "Udp network sendData error";
}

void RType::UdpNetwork::parseMultiplePacket(char *packet, std::size_t packetSize) {
    std::vector<std::string> packetList;
    boost::split(packetList, packet, boost::is_any_of("$"));
    for (auto &parsedPacket : packetList)
        this->parsePacket(parsedPacket);
}

void RType::UdpNetwork::parsePacket(std::string packet) {
    std::cout << "parsing a packet\r\n";
    std::vector<std::string> argv;
    boost::split(argv, packet, boost::is_any_of(";"));
    if (argv.empty())
        return;
    /// Update state packet
    if (std::strncmp(argv[0].c_str(), "0x498", 5) == 0 && argv.size() > 1) {
        if (std::strncmp(argv[1].c_str(), "0x415", 5) == 0 && argv.size() > 3) {
            ((ISceneManager*)this->_parent->getSceneManager())->updateMap(argv[2], argv[3]);
        }
    }
}

std::string *RType::UdpNetwork::getDestIp() const {
    return _destIp;
}

void RType::UdpNetwork::setDestIp(std::string *destIp) {
    _destIp = destIp;
}

unsigned short RType::UdpNetwork::getDestPort() const {
    return _destPort;
}

void RType::UdpNetwork::setDestPort(unsigned short destPort) {
    _destPort = destPort;
}

void RType::UdpNetwork::sayHello() {
    auto data = new std::string("Hello\r\n");
    this->sendData(*data);
}

void RType::UdpNetwork::sayUsername() {
    std::stringstream ss;
    ss << "username " << *this->_settings->getPlayerName() << " ;\r\n";
    this->sendData(ss.str());
}

void RType::UdpNetwork::startGame() {
    std::stringstream ss;
    ss << "START GAME ;\r\n";
    this->sendData(ss.str());
}
