//
// Created by luc4s.p on 11/15/19.
//

#include "MenuMusic.hpp"

RType::MenuMusic::MenuMusic() {
    this->_buffer.loadFromFile("assets/music/MainMenu.wav");
    this->_sound.setBuffer(this->_buffer);
}

void RType::MenuMusic::run() {
    this->_clock = new sf::Clock();
    this->_sound.play();
}

void RType::MenuMusic::stop() {
    this->_sound.stop();
}

void RType::MenuMusic::setVol(int vol) {
    this->_sound.setVolume(vol);
}