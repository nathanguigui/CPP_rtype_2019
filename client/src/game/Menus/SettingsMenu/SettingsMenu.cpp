//
// Created by guigui on 11/29/19.
//

#include "SettingsMenu.hpp"

RType::SettingsMenu::SettingsMenu(sf::RenderWindow *app, RType::IMenuManager *parent, RType::Settings *settings) : _app(
        app), _parent(parent), _settings(settings) {
    this->_status = QUIT_BUTTON;
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/MainMenu/Background.png");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_quitText = new sf::Text("QUIT", *this->_font);
    for (auto &bar : this->_volumeBar) {
        bar = new sf::Text("I", *this->_font);
        bar->setScale(0.4, 0.4);
    }
    this->initGUI();
    this->keyReleased = true;
    this->_soundmanager = new SoundManager(_settings);
}

void RType::SettingsMenu::initGUI() {
    auto screenSize = this->_app->getSize();
    this->updateState();
    this->_quitText->setPosition(colPos(screenSize, this->_quitText->getGlobalBounds().width, this->_quitText->getPosition(), 3, 2));
    this->_quitText->setPosition(linePos(screenSize, this->_quitText->getGlobalBounds().height, this->_quitText->getPosition(), 5, 5));
    for (int bar = 0; bar < 100; bar++) {
        this->_volumeBar[bar]->setPosition(centerY(screenSize, this->_volumeBar[bar]->getGlobalBounds().height, this->_volumeBar[bar]->getPosition()));
        this->_volumeBar[bar]->setPosition(colPos(screenSize, this->_volumeBar[bar]->getGlobalBounds().width, this->_volumeBar[bar]->getPosition(), 150, bar+25));
        this->_volumeBar[this->_volume]->setFillColor(sf::Color(sf::Color::White));
    }
}

void RType::SettingsMenu::updateState() {
    switch (this->_status) {
        case QUIT_BUTTON:
            this->_quitText->setFillColor(sf::Color(sf::Color::White));
            break;
        case VOLUME_BAR:
            this->_quitText->setFillColor(sf::Color(sf::Color::Black));
            this->_volumeBar[this->_volume - 1]->setFillColor(sf::Color(sf::Color::White));
            this->_volumeBar[this->_volume]->setFillColor(sf::Color(sf::Color::Black));
            break;
    }
}

void RType::SettingsMenu::handleLeft() {
    if (this->keyReleased) {
        switch (this->_status) {
            case QUIT_BUTTON:
                break;
        }
        this->keyReleased = false;
    } if (this->_status == VOLUME_BAR) {
        this->_volume = this->_volume != 1 ? this->_volume - 1 : this->_volume;
        this->updateState();
        this->_settings->setSoundVolume(this->_volume);
        this->_soundmanager->play("bubble");
    }
}

void RType::SettingsMenu::handleRight() {
    if (this->keyReleased) {
        switch (this->_status) {
            case QUIT_BUTTON:
                this->updateState();
                break;
        }
        this->keyReleased = false;
    } if (this->_status == VOLUME_BAR) {
        this->_volume = this->_volume != 99 ? this->_volume + 1 : this->_volume;
        this->updateState();
        this->_settings->setSoundVolume(this->_volume);
        this->_soundmanager->play("bubble");
    }
}

void RType::SettingsMenu::handleUp() {
    if (this->keyReleased) {
        switch (this->_status) {
            case QUIT_BUTTON:
                this->_status = VOLUME_BAR;
                this->updateState();
                break;
            case VOLUME_BAR:
                break;
        }
    }
}

void RType::SettingsMenu::handleDown() {
    if (this->keyReleased) {
        switch (this->_status) {
            case QUIT_BUTTON:
                break;
            case VOLUME_BAR:
                this->_status = QUIT_BUTTON;
                this->updateState();
                break;
        }
    }
}

void RType::SettingsMenu::handleEnter() {
    if (this->keyReleased) {
        switch (this->_status) {
            case QUIT_BUTTON:
                this->_parent->switchMenu(MenuType::MENU_MAIN_MENU);
                break;
            case VOLUME_BAR:
                break;
        }
    }
}

void RType::SettingsMenu::handleKeyReleased() {
    this->keyReleased = true;
}

void RType::SettingsMenu::draw() {
    this->_app->draw(*this->_backgroundSprite);
    this->_app->draw(*this->_quitText);
    for (auto &bar : this->_volumeBar)
        this->_app->draw(*bar);
}

void RType::SettingsMenu::handleText(sf::Event &evt) {

}

RType::SettingsMenu::~SettingsMenu() = default;
