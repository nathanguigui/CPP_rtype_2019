//
// Created by guigui on 11/12/19.
//

#include "WindowManager.hpp"

RType::WindowManager::WindowManager(const std::string &name): _name(name), _app(nullptr) {
}

RType::WindowManager::~WindowManager() = default;

int RType::WindowManager::run() {
    while (_app->isOpen()) {
        _eventManager->manageEvent();
        _app->display();
    }
    return RTYPE_noError;
}

void RType::WindowManager::init() {
    auto videoMode = sf::VideoMode(800, 600);
    this->_app = new sf::Window(videoMode, "R-Type");
    this->_eventManager = new Event(this, this->_app);
}
