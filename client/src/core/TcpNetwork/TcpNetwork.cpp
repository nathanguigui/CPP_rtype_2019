//
// Created by guigui on 11/25/19.
//

#include "TcpNetwork.hpp"

RType::TcpNetwork::TcpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                              Loading *loading, Settings *settings)
        : _app(app), _state(state), _destIp(destIp), _destPort(destPort), _loadingScreen(loading), _settings(settings) {
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

void RType::TcpNetwork::joinLobby(std::string *code, std::string *playerName) {
    auto ss = std::stringstream();
    ss << "LOBBY JOIN " << *code << " " << *playerName << ";\n€\n";
    this->sendData(ss.str());
}

void RType::TcpNetwork::lobbyReady(std::string code, std::string playerName) {
    auto ss = std::stringstream();
    ss << "LOBBY READY " << code << " " << playerName << ";\n€\n";
    this->sendData(ss.str());

}

void RType::TcpNetwork::lobbyInfo(std::string code) {
    auto ss = std::stringstream();
    ss << "LOBBY INFO " << code << ";\n€\n";
    this->sendData(ss.str());

}

void RType::TcpNetwork::lobbyStart(std::string code) {
    auto ss = std::stringstream();
    ss << "LOBBY START " << code << ";\n€\n";
    this->sendData(ss.str());
}

void RType::TcpNetwork::waitForPacket() {
    char data[1000];
    std::size_t received;
    if (this->_tcpSocket->receive(data, 100, received) != sf::Socket::Done)
        std::cout << "error" << std::endl;
    else
        this->parseMultiplePacket(data, received);
}

void RType::TcpNetwork::parsePacket(std::string command) {
    std::vector<std::string> argv;
    boost::split(argv, command, boost::is_any_of(" "));
    if (argv.empty())
        return;
    if (argv[0] == "LOBBY" && argv.size() > 1) {
        if (argv[1] == "CREATE" && argv.size() > 2) {
            if (argv[2] == "SUCCEED" && argv.size() > 3) {
                auto newCode = new::std::string(argv[3]);
                this->_settings->setLobbyCode(newCode);
                this->_state->setMenuType(MenuType::MENU_LOBBY_MENU);
            }
        }
    }
}

void RType::TcpNetwork::parseMultiplePacket(char *packet, std::size_t packetSize) {
    std::vector<std::string> response_arr;
    std::vector<std::string> packet_arr;

    boost::split(response_arr, packet, boost::is_any_of("\r\n"));
    if (response_arr.size() > 1) {
        this->parsePacket(response_arr[0]);
        /* TODO implement with real tcp
        boost::split(packet_arr, response_arr[0], boost::is_any_of("\n€"));
        for (const auto &packet_one : packet_arr)
            this->parsePacket(packet_one);
        */
    }
}

RType::TcpNetwork::~TcpNetwork() = default;
