
#include "SoundManager.hpp"

RType::SoundManager::SoundManager(Settings *settings) : _settings(settings) {

    this->_music = new MenuMusic();
    this->_quit = new QuitSound();
    this->_selected = new MenuSelectSound();
}

void RType::SoundManager::play(std::string type) {
    this->setVol();

    if (type == "bubble") {
        this->_selected->run();
    }
    if (type == "quit") {
        this->_quit->run();
    }
    if (type == "menumusic") {
        this->_music->run();
    }
}

void RType::SoundManager::stop(std::string type) {
    if (type == "menumusic") {
        this->_music->stop();
    }
}

void RType::SoundManager::setVol() {
    this->_music->setVol(this->_settings->getSoundVolume());
    this->_selected->setVol(this->_settings->getSoundVolume()); 
    this->_quit->setVol(this->_settings->getSoundVolume());   
}