//
// Created by guigui on 11/13/19.
//

#include "MainMenu.hpp"

RType::MainMenu::MainMenu(sf::RenderWindow *app, WindowState *state) : _app(app), _state(state) {
    this->_itemStatus = MAIN_MENU_JOIN_GAME;
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/background.jpg");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/default.ttf");
    this->_joinText = new sf::Text("JOIN GAME", *this->_font);
    this->_newText = new sf::Text("CREATE A GAME", *this->_font);
    this->_quitText = new sf::Text("QUIT", *this->_font);
    this->initGUI();
    this->keyReleased = true;
}

RType::MainMenu::~MainMenu() {

}

void RType::MainMenu::handleLeft() {
    std::cout << "click left";
}

void RType::MainMenu::handleRight() {
    std::cout << "click right";

}

void RType::MainMenu::handleUp() {
    if (this->keyReleased) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                break;
            case MAIN_MENU_JOIN_GAME:
                this->_itemStatus = MAIN_MENU_NEW_GAME;
                this->updateState();
                break;
            case MAIN_MENU_QUIT_GAME:
                this->_itemStatus = MAIN_MENU_JOIN_GAME;
                this->updateState();
                break;
        }
        this->keyReleased = false;
    }

}

void RType::MainMenu::handleDown() {
    if (this->keyReleased) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                this->_itemStatus = MAIN_MENU_JOIN_GAME;
                this->updateState();
                break;
            case MAIN_MENU_JOIN_GAME:
                this->_itemStatus = MAIN_MENU_QUIT_GAME;
                this->updateState();
                break;
            case MAIN_MENU_QUIT_GAME:
                break;
        }
        this->keyReleased = false;
    }

}

void RType::MainMenu::handleEnter() {
    if (this->keyReleased) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                break;
            case MAIN_MENU_JOIN_GAME:
                break;
            case MAIN_MENU_QUIT_GAME:
                exit(0);
        }
    }
}

void RType::MainMenu::draw() {
    this->_app->draw(*this->_backgroundSprite);
    this->_app->draw(*this->_joinText);
    this->_app->draw(*this->_newText);
    this->_app->draw(*this->_quitText);
}

void RType::MainMenu::updateState() {
    switch (this->_itemStatus) {
        case MAIN_MENU_NEW_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_newText->setFillColor(sf::Color(sf::Color::White));
            break;
        case MAIN_MENU_JOIN_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::White));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_newText->setFillColor(sf::Color(sf::Color::Black));
            break;
        case MAIN_MENU_QUIT_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::White));
            this->_newText->setFillColor(sf::Color(sf::Color::Black));
            break;
    }
}

void RType::MainMenu::initGUI() {
    auto screenSize = this->_app->getSize();
    this->updateState();
    this->_newText->setPosition(centerX(screenSize, this->_newText->getGlobalBounds().width, this->_newText->getPosition()));
    this->_newText->setPosition(linePos(screenSize, this->_newText->getGlobalBounds().height, this->_newText->getPosition(), 3, 1));
    this->_joinText->setPosition(centerX(screenSize, this->_joinText->getGlobalBounds().width, this->_joinText->getPosition()));
    this->_joinText->setPosition(linePos(screenSize, this->_joinText->getGlobalBounds().height, this->_joinText->getPosition(), 3, 2));
    this->_quitText->setPosition(centerX(screenSize, this->_quitText->getGlobalBounds().width, this->_quitText->getPosition()));
    this->_quitText->setPosition(linePos(screenSize, this->_quitText->getGlobalBounds().height, this->_quitText->getPosition(), 3, 3));
}

void RType::MainMenu::handleKeyReleased() {
    this->keyReleased = true;
}