//
// Created by luc4s.p on 11/15/19.
//

#include "MenuSelectSound.h"

RType::MenuSelectSound::MenuSelectSound() {
    this->_buffer.loadFromFile("assets/music/bubble.wav");
    this->_sound.setBuffer(this->_buffer);
}

void RType::MenuSelectSound::run() {
    this->_clock = new sf::Clock();
    this->_sound.play();
    if (this->_clock->getElapsedTime().asSeconds() > 0.5) {
        this->_sound.stop();
        return;
    }
}

void RType::MenuSelectSound::setVol(int vol) {
    this->_sound.setVolume(vol);
}