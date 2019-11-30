//
// Created by guigui on 11/13/19.
//

#include "MainMenu.hpp"

RType::MainMenu::MainMenu(sf::RenderWindow *app, WindowState *state, IMenuManager *parent, SoundManager *soundmanager) :
            _app(app), _state(state), _parent(parent), _soundmanager(soundmanager) {
    this->_itemStatus = MAIN_MENU_JOIN_GAME;
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/Background.png");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_backgroundSprite->setScale(_app->getSize().x/1200,_app->getSize().y/630);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_newText = new sf::Text("CREATE A GAME", *this->_font);
    this->_joinText = new sf::Text("JOIN GAME", *this->_font);
    this->_settingsText = new sf::Text("SETTINGS", *this->_font);
    this->_quitText = new sf::Text("QUIT", *this->_font);
    this->initGUI();
    this->keyReleased = true;    
}

RType::MainMenu::~MainMenu() = default;

void RType::MainMenu::handleLeft() {
}

void RType::MainMenu::handleRight() {
}

void RType::MainMenu::handleUp() {
    this->_soundmanager->play("bubble");
    if (this->keyReleased && !this->_disabled) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                break;
            case MAIN_MENU_JOIN_GAME:
                this->_itemStatus = MAIN_MENU_NEW_GAME;
                this->updateState();
                break;
            case MAIN_MENU_QUIT_GAME:
                this->_itemStatus = MAIN_MENU_SETTINGS;
                this->updateState();
                break;
            case MAIN_MENU_SETTINGS:
                this->_itemStatus = MAIN_MENU_JOIN_GAME;
                this->updateState();
                break;
        }
        this->keyReleased = false;
    }

}

void RType::MainMenu::handleDown() {
    this->_soundmanager->play("bubble");
    if (this->keyReleased && !this->_disabled) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                this->_itemStatus = MAIN_MENU_JOIN_GAME;
                this->updateState();
                break;
            case MAIN_MENU_JOIN_GAME:
                this->_itemStatus = MAIN_MENU_SETTINGS;
                this->updateState();
                break;
            case MAIN_MENU_QUIT_GAME:
                break;
            case MAIN_MENU_SETTINGS:
                this->_itemStatus = MAIN_MENU_QUIT_GAME;
                this->updateState();
                break;
        }
        this->keyReleased = false;
    }

}

void RType::MainMenu::handleEnter() {
    if (this->keyReleased && !this->_disabled) {
        switch (this->_itemStatus) {
            case MAIN_MENU_NEW_GAME:
                this->_parent->sendTcpCommand(ITcpNetwork::Commands::CREATE_LOBBY);
                //this->_state->setWindowMode(IN_GAME);
                //this->_disabled = true;
                break;
            case MAIN_MENU_JOIN_GAME:
                this->_parent->switchMenu(MENU_JOIN_LOBBY);
                break;
            case MAIN_MENU_QUIT_GAME:
                this->_soundmanager->stop("menumusic");
                this->_soundmanager->play("quit");
                sleep(3);
                exit(0);
            case MAIN_MENU_SETTINGS:
                this->_parent->switchMenu(MENU_SETTINGS);
                break;
        }
    }
}

void RType::MainMenu::draw() {
    this->_app->draw(*this->_backgroundSprite);
    this->_app->draw(*this->_joinText);
    this->_app->draw(*this->_newText);
    this->_app->draw(*this->_settingsText);
    this->_app->draw(*this->_quitText);
}

void RType::MainMenu::updateState() {
    switch (this->_itemStatus) {
        case MAIN_MENU_NEW_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_settingsText->setFillColor(sf::Color(sf::Color::Black));
            this->_newText->setFillColor(sf::Color(sf::Color::White));
            break;
        case MAIN_MENU_JOIN_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::White));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_settingsText->setFillColor(sf::Color(sf::Color::Black));
            this->_newText->setFillColor(sf::Color(sf::Color::Black));
            break;
        case MAIN_MENU_QUIT_GAME:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::White));
            this->_settingsText->setFillColor(sf::Color(sf::Color::Black));
            this->_newText->setFillColor(sf::Color(sf::Color::Black));
            break;
        case MAIN_MENU_SETTINGS:
            this->_joinText->setFillColor(sf::Color(sf::Color::Black));
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_settingsText->setFillColor(sf::Color(sf::Color::White));
            this->_newText->setFillColor(sf::Color(sf::Color::Black));
            break;
    }
}

void RType::MainMenu::initGUI() {
    auto screenSize = this->_app->getSize();
    this->updateState();
    this->_newText->setPosition(centerX(screenSize, this->_newText->getGlobalBounds().width, this->_newText->getPosition()));
    this->_newText->setPosition(linePos(screenSize, this->_newText->getGlobalBounds().height, this->_newText->getPosition(), 4, 1));
    this->_joinText->setPosition(centerX(screenSize, this->_joinText->getGlobalBounds().width, this->_joinText->getPosition()));
    this->_joinText->setPosition(linePos(screenSize, this->_joinText->getGlobalBounds().height, this->_joinText->getPosition(), 4, 2));
    this->_settingsText->setPosition(centerX(screenSize, this->_settingsText->getGlobalBounds().width, this->_settingsText->getPosition()));
    this->_settingsText->setPosition(linePos(screenSize, this->_settingsText->getGlobalBounds().height, this->_settingsText->getPosition(), 4, 3));
    this->_quitText->setPosition(centerX(screenSize, this->_quitText->getGlobalBounds().width, this->_quitText->getPosition()));
    this->_quitText->setPosition(linePos(screenSize, this->_quitText->getGlobalBounds().height, this->_quitText->getPosition(), 4, 4));
}

void RType::MainMenu::handleKeyReleased() {
    this->keyReleased = true;
}

void RType::MainMenu::handleText(sf::Event &evt) {

}

void RType::MainMenu::packetReceived(RType::ITcpReceiver::PacketType type, std::string data) {
}
