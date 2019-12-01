//
// Created by guigui on 11/13/19.
//

#include <iostream>
#include <client/src/core/core.hpp>
#include "WindowState.hpp"

RType::WindowState::WindowState(sf::RenderWindow *app) : _app(app) {}

bool RType::WindowState::isSplashDone() const {
    return splashDone;
}

void RType::WindowState::setSplashDone(bool splashDone) {
    WindowState::splashDone = splashDone;
}

bool RType::WindowState::isFirstLoadDone() const {
    return firstLoadDone;
}

void RType::WindowState::setFirstLoadDone(bool firstLoadDone) {
    WindowState::firstLoadDone = firstLoadDone;
}

bool RType::WindowState::isLoading() const {
    return loading;
}

void RType::WindowState::setIsLoading(bool isLoading) {
    WindowState::loading = isLoading;
}

RType::WindowMode RType::WindowState::getWindowMode() const {
    return windowMode;
}

void RType::WindowState::setWindowMode(RType::WindowMode windowMode) {
    WindowState::windowMode = windowMode;
}

void RType::WindowState::initState() {
    this->splashDone = false;
    this->firstLoadDone = false;
    this->loading = false;
    this->windowMode = IN_LAUNCH;
}

RType::MenuType RType::WindowState::getMenuType() const {
    return menuType;
}

void RType::WindowState::setMenuType(RType::MenuType menuType) {
    WindowState::menuType = menuType;
}

void RType::WindowState::addPlayer(const std::string& name) {
    if (std::find(this->_playerList.begin(), this->_playerList.end(),name) == this->_playerList.end()) {
        if (DEBUG_RTYPE)
            std::cout << name << " join the lobby\r\n";
        this->_playerList.push_back(name);
    }
}

int RType::WindowState::getPlayerCount() {
    this->_playerList.size();
}

bool RType::WindowState::isLobbyAdmin() const {
    return lobbyAdmin;
}

void RType::WindowState::setIsLobbyAdmin(bool isLobbyAdmin) {
    WindowState::lobbyAdmin = isLobbyAdmin;
}

std::string RType::WindowState::getPlayerName(int playerNb) {
    return this->_playerList[playerNb];
}

RType::WindowState::~WindowState() = default;
