//
// Created by guigui on 11/30/19.
//

#include <sstream>
#include "UdpNetwork.hpp"

RType::UdpNetwork::UdpNetwork(sf::RenderWindow *app, RType::WindowState *state, std::string *destIp,
                              const unsigned short destPort, RType::Settings *settings) : _app(app), _state(state),
                                                                                          _destIp(destIp),
                                                                                          _destPort(destPort),
                                                                                          _settings(settings) {
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

}

void RType::UdpNetwork::parsePacket(char *packet) {

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
