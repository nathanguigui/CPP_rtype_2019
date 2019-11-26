//
// Created by guigui on 11/25/19.
//

#include "TcpNetwork.hpp"

RType::TcpNetwork::TcpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                              Loading *loading)
        : _app(app), _state(state), _destIp(destIp), _destPort(destPort), _loadingScreen(loading) {
    this->_tcpSocket = new sf::TcpSocket();
}

void RType::TcpNetwork::connect() {
    auto destIp = sf::IpAddress(this->_destIp->c_str());
    this->_status = this->_tcpSocket->connect(destIp, this->_destPort);
    if (this->_status != sf::Socket::Done)
        throw Exception("cannot connect to tcp server", ExceptionType::NETWORK);
    if (DEBUG_RTYPE)
        std::cout << "Tcp network connected to lobby server";
    this->_loadingScreen->stop();
}

void RType::TcpNetwork::createLobby() {
    auto ss = std::stringstream();
    ss << "LOBBY CREATE;\n€\n";
    this->sendData(ss.str());
}

void RType::TcpNetwork::sendData(const std::string& data) {
    sf::Packet tmp;
    tmp << data;
    this->_tcpSocket->send(tmp);
}

RType::TcpNetwork::~TcpNetwork() = default;
