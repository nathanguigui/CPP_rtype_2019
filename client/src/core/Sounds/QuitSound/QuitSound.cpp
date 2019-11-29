//
// Created by luc4s.p on 11/15/19.
//

#include "QuitSound.h"

RType::QuitSound::QuitSound() {
    this->_buffer.loadFromFile("assets/music/Quit.wav");
    this->_sound.setBuffer(this->_buffer);
}

void RType::QuitSound::run() {
    this->_clock = new sf::Clock();
    this->_sound.play();
    if (this->_clock->getElapsedTime().asSeconds() > 3) {
        this->_sound.stop();
    }
}

void RType::QuitSound::setVol(int vol) {
    this->_sound.setVolume(vol);
}
