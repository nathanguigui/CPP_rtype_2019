//
// Created by guigui on 11/12/19.
//

#include "WindowManager.hpp"

RType::WindowManager::WindowManager(const std::string &name): _name(name) {
}

RType::WindowManager::~WindowManager() = default;

int RType::WindowManager::run() {
    this->gameLoop();
    return RTYPE_noError;
}

void RType::WindowManager::init() {
    auto videoMode = sf::VideoMode(800, 600);
    this->_app = new sf::RenderWindow(videoMode, "R-Type");
    this->_state = new WindowState(this->_app);
    this->_eventManager = new Event(this, this->_app);
    this->_settings = new Settings();
}

void RType::WindowManager::gameLoop() {
    while (_app->isOpen()) {
        _eventManager->manageEvent();
        _app->display();
    }
}

void RType::WindowManager::processParams(int ac, char **av) {
    std::cout << "check arg count and type then throw error if need";
    this->init();
}
