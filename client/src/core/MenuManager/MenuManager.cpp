//
// Created by guigui on 11/26/19.
//

#include "MenuManager.hpp"

RType::MenuManager::MenuManager(WindowState *state, Event *event, sf::RenderWindow *app, TcpNetwork *network,
                                Settings *settings)
        : _state(state), _event(event), _app(app), _network(network), _settings(settings) {
    this->_mainMenu = new MainMenu(this->_app, this->_state, this);
    this->_joinLobby = new JoinLobby(this->_app, this->_state, this);
    this->_lobbyMenu = new Lobby(this->_app, this->_state, this, this->_settings);
}

RType::MenuManager::~MenuManager() = default;

void RType::MenuManager::draw() {
    switch (this->_state->getMenuType()) {
        case MENU_MAIN_MENU:
            this->_mainMenu->draw();
            break;
        case MENU_LOBBY_MENU:
            this->_lobbyMenu->draw();
            break;
        case MENU_JOIN_LOBBY:
            this->_joinLobby->draw();
            break;
    }
}

void RType::MenuManager::switchMenu(RType::MenuType menuType) {
    switch (menuType) {
        case MENU_MAIN_MENU:
            this->_event->setCurrentMenu((IMenu*)this->_mainMenu);
            break;
        case MENU_LOBBY_MENU:
            this->_lobbyMenu->updateCode();
            this->_event->setCurrentMenu((IMenu*)this->_lobbyMenu);
            break;
        case MENU_JOIN_LOBBY:
            this->_event->setCurrentMenu((IMenu*)this->_joinLobby);
            break;
    }
    this->_state->setMenuType(menuType);
}

void RType::MenuManager::sendTcpCommand(RType::TcpNetwork::Commands commands) {
    switch (commands) {
        case TcpNetwork::CREATE_LOBBY:
            this->_network->createLobby();
            this->_state->setIsLoading(true);
            this->_network->waitForPacket();
            this->_state->setIsLoading(false);
            break;
        case TcpNetwork::JOIN_LOBBY:
            if (this->_settings->getLobbyCode() != nullptr)
                this->_network->joinLobby(this->_settings->getLobbyCode(), this->_settings->getPlayerName());
            break;
        case TcpNetwork::READY_LOBBY:
            break;
        case TcpNetwork::INFO_LOBBY:
            break;
        case TcpNetwork::START_LOBBY:
            break;
    }
}

void RType::MenuManager::setLobbyCode(std::string *code) {
    this->_settings->setLobbyCode(code);
}
