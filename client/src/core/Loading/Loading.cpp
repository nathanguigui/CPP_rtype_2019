//
// Created by glithaud on 11/15/19.
//

#include "Loading.hpp"
#include <iostream>

RType::Loading::Loading(sf::RenderWindow *app, WindowState *state, float time) : _app(app), _state(state), _timeToWait(time) {
    this->_backTexture = new sf::Texture();
    this->_backTexture->loadFromFile("assets/loading/loading.jpg");
    this->_backSprite.setTexture(*this->_backTexture);
    this->_backSprite.setScale(2, 1);
    this->_mode = IN_MENU;
    this->_isLaunched = false;
    this->_clock = new sf::Clock();
}

void RType::Loading::setNextMode(RType::WindowMode tmp) {
    this->_mode = tmp;
}

RType::WindowMode RType::Loading::getNextMode() {
    return (this->_mode);
}

void RType::Loading::setTimeToWait(float time) {
    this->_timeToWait = time;
}

float RType::Loading::getTimeToWait() {
    return (this->_timeToWait);
}

bool RType::Loading::isLaunched() {
    return (this->_isLaunched);
}

void RType::Loading::launch() {
    this->_clock->restart();
    this->_time = this->_clock->getElapsedTime();
    this->_app->draw(this->_backSprite);
    this->_isLaunched = true;
    std::cout << "LOADING LAUNCHED";

}

void RType::Loading::check() {
    this->_time += this->_clock->getElapsedTime();
    this->_clock->restart();
    this->_app->draw(this->_backSprite);
    if (this->_time.asSeconds() > this->_timeToWait) {
        this->_state->setIsLoading(false);
        this->_state->setWindowMode(this->_mode);
        this->_isLaunched = false;
        std::cout << "END LOADING";
    }
}

void RType::Loading::stop() {
    this->_state->setIsLoading(false);
    this->_state->setWindowMode(this->_mode);
    this->_isLaunched = false;
}

RType::Loading::~Loading() {

}
