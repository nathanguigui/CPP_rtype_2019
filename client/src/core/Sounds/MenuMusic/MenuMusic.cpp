//
// Created by luc4s.p on 11/15/19.
//

#include "MenuMusic.h"

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