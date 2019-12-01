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
    /// Update entity packet
    if (std::strncmp(argv[0].c_str(), "0x698", 5) == 0 && argv.size() > 1) {
        /// Player
        if (std::strncmp(argv[1].c_str(), "0x655", 5) == 0 && argv.size() > 6) {
            if (std::strncmp(argv[4].c_str(), "0x610", 5) == 0 && argv.size() > 10) {
                try {
                    int score = std::stoi(argv[5]);
                    int life = std::stoi(argv[6]);
                    int attackSpeed = std::stoi(argv[7]);
                    int posX = std::stoi(argv[8]);
                    int posY = std::stoi(argv[9]);
                    ISceneManager::ForcePodLevel forcePodLevel = ISceneManager::LOW_POWER;
                    if (std::strncmp(argv[10].c_str(), "0x615", 5) == 0)
                        forcePodLevel = ISceneManager::LOW_POWER;
                    if (std::strncmp(argv[10].c_str(), "0x616", 5) == 0)
                        forcePodLevel = ISceneManager::MEDIUM_POWER;
                    if (std::strncmp(argv[10].c_str(), "0x617", 5) == 0)
                        forcePodLevel = ISceneManager::HIGH_POWER;
                    ((ISceneManager*)this->_parent->getSceneManager())->updatePlayer(argv[2], argv[3],
                            ISceneManager::ALIVE, score, life, attackSpeed, posX, posY, forcePodLevel);
                } catch (std::invalid_argument const &e) {}
            } else if (std::strncmp(argv[4].c_str(), "0x610", 5) == 0 && argv.size() > 5) {
                try {
                    int score = std::stoi(argv[5]);
                    ((ISceneManager*)this->_parent->getSceneManager())->updatePlayer(argv[2], argv[3],
                            ISceneManager::DEAD, score);
                } catch (std::invalid_argument const &e) {}
            }
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

void RType::UdpNetwork::update() {
    if (_needUpdate) {
        std::stringstream ss;
        ss << "UPDATE ;\r\n";
        this->sendData(ss.str());
    }
}

bool RType::UdpNetwork::isNeedUpdate() const {
    return _needUpdate;
}

void RType::UdpNetwork::setNeedUpdate(bool needUpdate) {
    _needUpdate = needUpdate;
}
