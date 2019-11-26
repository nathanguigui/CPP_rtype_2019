//
// Created by guigui on 11/26/19.
//

#include "JoinLobby.hpp"

RType::JoinLobby::JoinLobby(sf::RenderWindow *app, RType::WindowState *state) : _app(app), _state(state) {
    this->_lobbyStatus = JOIN_LOBBY_JOIN;
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/background.jpg");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_joinText = new sf::Text("JOIN GAME", *this->_font);
    this->_quitText = new sf::Text("QUIT", *this->_font);
    this->_string = new sf::String();
    this->_textField = new sf::Text("Enter player name", *this->_font);
    this->keyReleased = true;
}

RType::JoinLobby::~JoinLobby() {

}

void RType::JoinLobby::initGUI() {
    auto screenSize = this->_app->getSize();
    this->updateState();
    this->_quitText->setPosition(colPos(screenSize, this->_quitText->getGlobalBounds().width, this->_quitText->getPosition(), 3, 1));
}

void RType::JoinLobby::updateState() {
    switch (this->_lobbyStatus) {
        case JOIN_LOBBY_JOIN:
            this->_joinText->setFillColor(sf::Color(sf::Color::White));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            break;
        case JOIN_LOBBY_EXIT:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::White));
            break;
    }
}

void RType::JoinLobby::handleLeft() {

}

void RType::JoinLobby::handleRight() {

}

void RType::JoinLobby::handleUp() {

}

void RType::JoinLobby::handleDown() {

}

void RType::JoinLobby::handleEnter() {

}

void RType::JoinLobby::handleKeyReleased() {

}

void RType::JoinLobby::draw() {

}

void RType::JoinLobby::handleText(sf::Event &evt) {

}
