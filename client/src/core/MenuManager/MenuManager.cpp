//
// Created by guigui on 11/26/19.
//

#include "MenuManager.hpp"

RType::MenuManager::MenuManager(WindowState *state, Event *event, sf::RenderWindow *app, TcpNetwork *network,
                                Settings *settings, LoadScreen *loadScreen)
        : _state(state), _event(event), _app(app), _network(network), _settings(settings), _loadScreen(loadScreen) {
    this->_soundmanager = new SoundManager(settings);    
    this->_mainMenu = new MainMenu(this->_app, this->_state, this, this->_soundmanager);
    this->_joinLobby = new JoinLobby(this->_app, this->_state, this, this->_soundmanager);
    this->_lobbyMenu = new Lobby(this->_app, this->_state, this, this->_settings);
    this->_settingsMenu = new SettingsMenu(this->_app, this, this->_settings);
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
        case MENU_SETTINGS:
            this->_settingsMenu->draw();
            break;
    }
}

void RType::MenuManager::switchMenu(RType::MenuType menuType) {
    switch (menuType) {
        case MENU_MAIN_MENU:
            this->_soundmanager->play("menumusic");
            this->_event->setCurrentMenu((IMenu*)this->_mainMenu);
            break;
        case MENU_LOBBY_MENU:
            this->_soundmanager->play("menumusic");
            this->_lobbyMenu->updateCode();
            this->_event->setCurrentMenu((IMenu*)this->_lobbyMenu);
            break;
        case MENU_JOIN_LOBBY:
            this->_soundmanager->stop("menumusic");
            this->_event->setCurrentMenu((IMenu*)this->_joinLobby);
            break;
        case MENU_SETTINGS:
            this->_event->setCurrentMenu((IMenu*)this->_settingsMenu);
            break;
    }
    this->_state->setMenuType(menuType);
}

void RType::MenuManager::sendTcpCommand(RType::TcpNetwork::Commands commands) {
    switch (commands) {
        case TcpNetwork::CREATE_LOBBY:
            this->_network->createLobby(this->_settings->getPlayerName());
            this->_state->setIsLoading(true);
            this->_loadScreen->run();
            //while (!this->_network->waitForPacket());
            this->_state->setIsLoading(false);
            break;
        case TcpNetwork::JOIN_LOBBY:
            if (this->_settings->getLobbyCode() != nullptr) {
                this->_network->joinLobby(this->_settings->getLobbyCode(), this->_settings->getPlayerName());
                //while (!this->_network->waitForPacket());
            }
            break;
        case TcpNetwork::READY_LOBBY:
            break;
        case TcpNetwork::INFO_LOBBY:
            break;
        case TcpNetwork::START_LOBBY:
            if (this->_settings->getLobbyCode() != nullptr)
                this->_network->lobbyStart();
            break;
    }
}

void RType::MenuManager::setLobbyCode(std::string *code) {
    this->_settings->setLobbyCode(code);
}

RType::MenuManager::MenuManager(sf::RenderWindow *app, RType::IWindowManager *parent) : _app(app), _parent(parent) {
    this->_state = (WindowState*)this->_parent->getWindowState();
    this->_network = (TcpNetwork*)this->_parent->getTcpNetwork();
    this->_event = (Event*)this->_parent->getEvent();
    this->_settings = (Settings*)this->_parent->getSettings();
    this->_soundmanager = new SoundManager(this->_settings);
    this->_loadScreen = (LoadScreen*)this->_parent->getLoadScreen();
    this->_mainMenu = new MainMenu(this->_app, this->_state, this, this->_soundmanager);
    this->_joinLobby = new JoinLobby(this->_app, this->_state, this, this->_soundmanager);
    this->_lobbyMenu = new Lobby(this->_app, this->_state, this, this->_settings);
    this->_settingsMenu = new SettingsMenu(this->_app, this, this->_settings);
}
