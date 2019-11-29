//
// Created by guigui on 11/26/19.
//

#include "JoinLobby.hpp"

RType::JoinLobby::JoinLobby(sf::RenderWindow *app, RType::WindowState *state, IMenuManager *parent, SoundManager *soundmanager)
        : _app(app), _state(state), _parent(parent), _soundmanager(soundmanager) {
    this->_lobbyStatus = JOIN_LOBBY_JOIN;
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/Background.png");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_joinText = new sf::Text("JOIN GAME", *this->_font);
    this->_quitText = new sf::Text("QUIT", *this->_font);
    this->_textField = new sf::Text("Enter player name", *this->_font);
    this->initGUI();
    this->keyReleased = true;
}

RType::JoinLobby::~JoinLobby() {

}

void RType::JoinLobby::initGUI() {
    auto screenSize = this->_app->getSize();
    this->updateState();
    this->_quitText->setPosition(colPos(screenSize, this->_quitText->getGlobalBounds().width, this->_quitText->getPosition(), 3, 1));
    this->_quitText->setPosition(linePos(screenSize, this->_quitText->getGlobalBounds().height, this->_quitText->getPosition(), 5, 5));
    this->_joinText->setPosition(colPos(screenSize, this->_joinText->getGlobalBounds().width, this->_joinText->getPosition(), 3, 3));
    this->_joinText->setPosition(linePos(screenSize, this->_joinText->getGlobalBounds().height, this->_joinText->getPosition(), 5, 5));
    this->_textField->setPosition(centerX(screenSize, this->_textField->getGlobalBounds().width, this->_textField->getPosition()));
    this->_textField->setPosition(centerY(screenSize, this->_textField->getGlobalBounds().height, this->_textField->getPosition()));
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
    this->_soundmanager->play("bubble");
    if (this->keyReleased) {
        switch (this->_lobbyStatus) {
            case JOIN_LOBBY_JOIN:
                this->_lobbyStatus = JOIN_LOBBY_EXIT;
                this->updateState();
                break;
            case JOIN_LOBBY_EXIT:
                break;
        }
        this->keyReleased = false;
    }
}

void RType::JoinLobby::handleRight() {
    this->_soundmanager->play("bubble");
    if (this->keyReleased) {
        switch (this->_lobbyStatus) {
            case JOIN_LOBBY_JOIN:
                break;
            case JOIN_LOBBY_EXIT:
                this->_lobbyStatus = JOIN_LOBBY_JOIN;
                this->updateState();
                break;
        }
        this->keyReleased = false;
    }
}

void RType::JoinLobby::handleUp() {

}

void RType::JoinLobby::handleDown() {

}

void RType::JoinLobby::handleEnter() {
    if (this->keyReleased) {
        switch (this->_lobbyStatus) {
            case JOIN_LOBBY_JOIN:
                if (this->_textField->getString().getSize() > 0) {
                    auto code = this->_string.toAnsiString();
                    auto newCode = new std::string(code);
                    this->_parent->setLobbyCode(newCode);
                    this->_parent->sendTcpCommand(ITcpNetwork::Commands::JOIN_LOBBY);
                }
                break;
            case JOIN_LOBBY_EXIT:
                this->_parent->switchMenu(MENU_MAIN_MENU);
                break;
        }
    }
}

void RType::JoinLobby::handleKeyReleased() {
    this->keyReleased = true;
}

void RType::JoinLobby::draw() {
    this->_app->draw(*this->_backgroundSprite);
    this->_app->draw(*this->_joinText);
    this->_app->draw(*this->_quitText);
    this->_app->draw(*this->_textField);
}

void RType::JoinLobby::handleText(sf::Event &evt) {
    if(evt.text.unicode == '\b' && this->_string.getSize())
        this->_string.erase(this->_string.getSize()-1,1);
    else if (evt.text.unicode < 123 && evt.text.unicode > 47)
        this->_string += evt.text.unicode;
    this->_textField->setString(this->_string);
    auto screenSize = this->_app->getSize();
    this->_textField->setPosition(centerX(screenSize, this->_textField->getGlobalBounds().width, this->_textField->getPosition()));
    this->_textField->setPosition(centerY(screenSize, this->_textField->getGlobalBounds().height, this->_textField->getPosition()));
}
