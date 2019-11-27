//
// Created by guigui on 11/13/19.
//

#include "Settings.hpp"

RType::Settings::Settings(WindowState *state): _windowState(state) {
}

void RType::Settings::checkIp(char *ip) {
    std::vector<std::string> result;
    boost::split(result, ip, boost::is_any_of("."));
    if (result.size() != 4)
        throw Exception("invalid ip", STARTUP);
    for (auto &i : result)
        if (!std::all_of(i.begin(), i.end(), ::isdigit) || i.empty())
            throw Exception("invalid ip", STARTUP);
    this->_lobbyServerIp = new std::string(ip);
}

void RType::Settings::checkPort(char *port) {
    auto tmp = std::string(port);
    if (!std::all_of(tmp.begin(), tmp.end(), ::isdigit))
        throw Exception("invalid port", STARTUP);
    this->_lobbyServerPort = (unsigned short) strtoul(port, nullptr, 0);
}

void RType::Settings::checkUsername(char *username) {
    auto tmp = std::string(username);
    if (tmp.find_first_not_of("poiuytrezamlkjhgfdsqnbvcxwPOIUYTREZAMLKJHGFDSQNBVCXW0987654321") != std::string::npos)
        throw Exception("invalid username", STARTUP);
    this->_playerName = new std::string(username);
}

void RType::Settings::debugArgs() {
    std::cout << "Arguments successfully processed\r\n\t[SERVER_IP] => " << *this->_lobbyServerIp << "\r\n\t[SERVER_PORT] => "
    << this->_lobbyServerPort << "\r\n\t[USERNAME] => " << *this->_playerName << "\r\n";
}

std::string *RType::Settings::getPlayerName() const {
    return _playerName;
}

std::string *RType::Settings::getLobbyServerIp() const {
    return _lobbyServerIp;
}

unsigned short RType::Settings::getLobbyServerPort() const {
    return _lobbyServerPort;
}

std::string *RType::Settings::getLobbyCode() const {
    return _lobbyCode;
}

void RType::Settings::setLobbyCode(std::string *lobbyCode) {
    _lobbyCode = lobbyCode;
}

RType::Settings::~Settings() = default;