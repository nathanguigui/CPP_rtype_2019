//
// Created by guigui on 11/25/19.
//

#include <client/src/core/UdpNetwork/IUdpNetwork.hpp>
#include <client/src/core/Event/Event.hpp>
#include "TcpNetwork.hpp"

RType::TcpNetwork::TcpNetwork(sf::RenderWindow *app, WindowState *state, std::string *destIp, unsigned short destPort,
                              Loading *loading, Settings *settings, IWindowManager *parent)
        : _app(app), _state(state), _destIp(destIp), _destPort(destPort), _loadingScreen(loading), _settings(settings), _parent(parent) {
    this->_tcpSocket = new sf::TcpSocket();
    this->_udpNetwork = (UdpNetwork*)this->_parent->getUdpNetwork();
    this->_event = (Event*)this->_parent->getEvent();

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

void RType::TcpNetwork::createLobby(std::string *playerName) {
    auto ss = std::stringstream();
    ss << "LOBBY CREATE " << *playerName << "\r\n";
    this->sendData(ss.str());
}

void RType::TcpNetwork::sendData(const std::string& data) {
    this->_tcpSocket->send(data.c_str(), data.size());
}

void RType::TcpNetwork::joinLobby(std::string *code, std::string *playerName) {
    auto ss = std::stringstream();
    ss << "LOBBY JOIN " << *code << " " << *playerName << "\r\n";
    this->sendData(ss.str());
}

void RType::TcpNetwork::lobbyReady(std::string code, std::string playerName) {
    auto ss = std::stringstream();
    ss << "LOBBY READY " << code << " " << playerName << "\n€\n";
    this->sendData(ss.str());

}

void RType::TcpNetwork::lobbyUpdate() {
    auto ss = std::stringstream();
    ss << "LOBBY UPDATE " << *this->_settings->getPlayerName() << "\r\n";
    this->sendData(ss.str());

}

void RType::TcpNetwork::lobbyStart() {
    auto ss = std::stringstream();
    ss << "LOBBY START " << *this->_settings->getLobbyCode() << "\r\n";
    this->sendData(ss.str());
    this->_udpNetwork = (UdpNetwork*)this->_parent->getUdpNetwork();
    this->_udpNetwork->startGame();
}

bool RType::TcpNetwork::waitForPacket() {
    sf::SocketSelector aSelector;
    aSelector.add(*this->_tcpSocket);
    if (aSelector.wait(sf::milliseconds(TCP_SOCKET_SELECTOR_TIMEOUT))) {
        if (aSelector.isReady(*this->_tcpSocket)) {
            char data[1000];
            std::size_t received;
            if (this->_tcpSocket->receive(data, 100, received) != sf::Socket::Done)
                std::cout << "error on tcp receive" << std::endl;
            else
                this->parseMultiplePacket(data, received);
            return true;
        }
    } else
        return false;
}

void RType::TcpNetwork::parsePacket(std::string command) {
    std::vector<std::string> cmdLines;
    boost::split(cmdLines, command, boost::is_any_of("\r\n"));
    std::vector<std::string> argv;

    for (const auto &line : cmdLines) {
        boost::split(argv, command, boost::is_any_of(" "));
        if (argv.empty())
            continue;
        this->execArgv(argv);
    }
}

void RType::TcpNetwork::parseMultiplePacket(char *packet, std::size_t packetSize) {
    std::vector<std::string> response_arr;
    std::vector<std::string> argv;

    boost::split(response_arr, packet, boost::is_any_of("€"));
    if (!response_arr.empty()) {
        for (const auto &packet_str : response_arr)
            this->parsePacket(packet_str);
    }
}

void RType::TcpNetwork::setMenuManager(RType::IMenuManager *menuManager) {
    _menuManager = menuManager;
}

void RType::TcpNetwork::execArgv(std::vector<std::string> argv) {
    this->_udpNetwork = (UdpNetwork*)this->_parent->getUdpNetwork();
    this->_event = (Event*)this->_parent->getEvent();
    this->_menuManager = (IMenuManager*)this->_parent->getMenuManager();
    std::vector<std::string> tmp;
    if (argv[0] == "CREATE" && argv.size() > 2) {
        auto newCode = new::std::string(argv[1]);
        this->_settings->setLobbyCode(newCode);
        boost::split(tmp, argv[2], boost::is_any_of(":"));
        this->_settings->setGameServerPort(tmp[1].c_str());
        this->_udpNetwork->setDestPort(this->_settings->getGameServerPort());
        this->_udpNetwork->sayHello();
        this->_udpNetwork->sayUsername();
        this->_state->setIsLobbyAdmin(true);
        this->_inLobby = true;
        if (this->_menuManager != nullptr)
            this->_menuManager->switchMenu(MenuType::MENU_LOBBY_MENU);
    } if (argv[0] == "JOIN" && argv.size() > 1) {
        boost::split(tmp, argv[1], boost::is_any_of(":"));
        this->_settings->setGameServerPort(tmp[1].c_str());
        this->_udpNetwork->setDestPort(this->_settings->getGameServerPort());
        this->_udpNetwork->sayHello();
        this->_udpNetwork->sayUsername();
        this->_inLobby = true;
        if (this->_menuManager != nullptr)
            this->_menuManager->switchMenu(MenuType::MENU_LOBBY_MENU);
    } if (std::strncmp(argv[0].c_str(), "UPDATE", 6) == 0) {
        boost::split(tmp, argv[0], boost::is_any_of("\r\n"));
        for (auto &item : tmp) {
            if (std::strncmp(item.c_str(), "UPDATE", 6) != 0 && std::strncmp(item.c_str(), "\r", 1) != 0 && !item.empty() && std::strncmp(item.c_str(), "\n", 1) != 0)
                this->_state->addPlayer(item);
        }
        this->_addingPlayer = !this->_addingPlayer;
    } if (std::strncmp(argv[0].c_str(), "START", 5) == 0) {
        if (DEBUG_RTYPE)
            std::cout << "starting game...\r\n";
        this->_event->removeCurrentMenu();
        this->_state->setWindowMode(WindowMode::IN_GAME);
        this->_inLobby = false;
    }
}

void RType::TcpNetwork::update() {
    if (this->_inLobby)
        this->lobbyUpdate();
}

RType::TcpNetwork::TcpNetwork(sf::RenderWindow *app, RType::IWindowManager *parent) : _app(app), _parent(parent) {
    this->_tcpSocket = new sf::TcpSocket();
    this->_udpNetwork = (UdpNetwork*)this->_parent->getUdpNetwork();
    this->_state = (WindowState*)this->_parent->getWindowState();
    this->_loadingScreen = (Loading*)this->_parent->getLoading();
    this->_settings = (Settings*)this->_parent->getSettings();
    this->_event = (Event*)this->_parent->getEvent();
    this->_destIp = this->_settings->getLobbyServerIp();
    this->_destPort = this->_settings->getLobbyServerPort();
}

RType::TcpNetwork::~TcpNetwork() = default;
