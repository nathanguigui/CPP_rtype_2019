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
    this->_playerOneText = new sf::Text(*this->_settings->getPlayerName(), *this->_font);
    this->_playerOneText->setScale(0.5, 0.5);
    this->_playerTwoText = new sf::Text("WAITING FOR PLAYER", *this->_font);
    this->_playerTwoText->setScale(0.5, 0.5);
    this->_playerThreeText = new sf::Text("WAITING FOR PLAYER", *this->_font);
    this->_playerThreeText->setScale(0.5, 0.5);
    this->_playerFourText = new sf::Text("WAITING FOR PLAYER", *this->_font);
    this->_playerFourText->setScale(0.5, 0.5);
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
    this->_playerOneText->setPosition(colPos(screenSize, this->_playerOneText->getGlobalBounds().width, this->_playerOneText->getPosition(), 5, 1));
    this->_playerOneText->setPosition(linePos(screenSize, this->_playerOneText->getGlobalBounds().height, this->_playerOneText->getPosition(), 10, 3));
    this->_playerTwoText->setPosition(colPos(screenSize, this->_playerTwoText->getGlobalBounds().width, this->_playerTwoText->getPosition(), 5, 1));
    this->_playerTwoText->setPosition(linePos(screenSize, this->_playerTwoText->getGlobalBounds().height, this->_playerTwoText->getPosition(), 10, 4));
    this->_playerThreeText->setPosition(colPos(screenSize, this->_playerThreeText->getGlobalBounds().width, this->_playerThreeText->getPosition(), 5, 1));
    this->_playerThreeText->setPosition(linePos(screenSize, this->_playerThreeText->getGlobalBounds().height, this->_playerThreeText->getPosition(), 10, 5));
    this->_playerFourText->setPosition(colPos(screenSize, this->_playerFourText->getGlobalBounds().width, this->_playerFourText->getPosition(), 5, 1));
    this->_playerFourText->setPosition(linePos(screenSize, this->_playerFourText->getGlobalBounds().height, this->_playerFourText->getPosition(), 10, 6));
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
    this->_app->draw(*this->_playerOneText);
    this->_app->draw(*this->_playerTwoText);
    this->_app->draw(*this->_playerThreeText);
    this->_app->draw(*this->_playerFourText);
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
