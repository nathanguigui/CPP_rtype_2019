//
// Created by guigui on 11/13/19.
//

#include "Settings.hpp"

RType::Settings::Settings() = default;

RType::Settings::~Settings() = default;

int RType::Settings::getServerPort() const {
    return serverPort;
}

void RType::Settings::setServerPort(int serverPort) {
    Settings::serverPort = serverPort;
}

const std::string &RType::Settings::getServerIp() const {
    return serverIp;
}

void RType::Settings::setServerIp(const std::string &serverIp) {
    Settings::serverIp = serverIp;
}