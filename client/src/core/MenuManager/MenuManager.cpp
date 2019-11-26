//
// Created by guigui on 11/26/19.
//

#include "MenuManager.hpp"

RType::MenuManager::MenuManager(RType::WindowState *state, RType::Event *event, sf::RenderWindow *app) : _state(state),
                                                                                                         _event(event),
                                                                                                         _app(app) {
    this->_mainMenu = new MainMenu(this->_app, this->_state);
    this->_joinLobby = new JoinLobby(this->_app, this->_state);
}

RType::MenuManager::~MenuManager() = default;

void RType::MenuManager::draw() {
    switch (this->_state->getMenuType()) {
        case MENU_MAIN_MENU:
            this->_mainMenu->draw();
            break;
        case MENU_LOBBY_MENU:
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
            break;
        case MENU_JOIN_LOBBY:
            this->_event->setCurrentMenu((IMenu*)this->_joinLobby);
            break;
    }
    this->_state->setMenuType(menuType);
}
