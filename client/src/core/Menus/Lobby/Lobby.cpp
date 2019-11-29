//
// Created by guigui on 11/29/19.
//

#include "Lobby.hpp"

RType::Lobby::Lobby(sf::RenderWindow *app, WindowState *state, IMenuManager *parent, Settings *settings)
            : _app(app), _state(state), _parent(parent), _settings(settings) {
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/background.jpg");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_startText = new sf::Text("START GAME", *this->_font);
    this->_codeText = new sf::Text(*this->_settings->getLobbyCode(), *this->_font);
    this->initGUI();
    this->keyReleased = true;
}

RType::Lobby::~Lobby() {

}

void RType::Lobby::initGUI() {
    auto screenSize = this->_app->getSize();
    this->_codeText->setPosition(centerX(screenSize, this->_codeText->getGlobalBounds().width, this->_codeText->getPosition()));
    this->_codeText->setPosition(linePos(screenSize, this->_codeText->getGlobalBounds().height, this->_codeText->getPosition(), 5, 1));
    this->_startText->setPosition(colPos(screenSize, this->_startText->getGlobalBounds().width, this->_startText->getPosition(), 3, 3));
    this->_startText->setPosition(linePos(screenSize, this->_startText->getGlobalBounds().height, this->_startText->getPosition(), 5, 5));
}

void RType::Lobby::handleUp() {

}

void RType::Lobby::handleDown() {

}

void RType::Lobby::handleEnter() {

}

void RType::Lobby::handleKeyReleased() {

}

void RType::Lobby::draw() {
    auto screenSize = this->_app->getSize();
    this->_codeText->setString(*this->_settings->getLobbyCode());
    this->_codeText->setPosition(centerX(screenSize, this->_codeText->getGlobalBounds().width, this->_codeText->getPosition()));
    this->_codeText->setPosition(linePos(screenSize, this->_codeText->getGlobalBounds().height, this->_codeText->getPosition(), 5, 1));
    this->_app->draw(*this->_backgroundSprite);
    this->_app->draw(*this->_startText);
    this->_app->draw(*this->_codeText);
}

void RType::Lobby::handleText(sf::Event &evt) {
}

void RType::Lobby::handleLeft() {

}

void RType::Lobby::handleRight() {

}

void RType::Lobby::updateCode() {
    auto screenSize = this->_app->getSize();
    this->_codeText->setString(*this->_settings->getLobbyCode());
    this->_codeText->setPosition(centerX(screenSize, this->_codeText->getGlobalBounds().width, this->_codeText->getPosition()));
    this->_codeText->setPosition(linePos(screenSize, this->_codeText->getGlobalBounds().height, this->_codeText->getPosition(), 5, 1));
}
