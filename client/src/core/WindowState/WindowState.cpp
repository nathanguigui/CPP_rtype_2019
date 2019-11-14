//
// Created by guigui on 11/13/19.
//

#include "WindowState.hpp"

RType::WindowState::WindowState(sf::RenderWindow *app) : _app(app) {}

bool RType::WindowState::isSplashDone() const {
    return splashDone;
}

void RType::WindowState::setSplashDone(bool splashDone) {
    WindowState::splashDone = splashDone;
}

bool RType::WindowState::isFirstLoadDone() const {
    return firstLoadDone;
}

void RType::WindowState::setFirstLoadDone(bool firstLoadDone) {
    WindowState::firstLoadDone = firstLoadDone;
}

bool RType::WindowState::isLoading() const {
    return loading;
}

void RType::WindowState::setIsLoading(bool isLoading) {
    WindowState::loading = isLoading;
}

RType::WindowMode RType::WindowState::getWindowMode() const {
    return windowMode;
}

void RType::WindowState::setWindowMode(RType::WindowMode windowMode) {
    WindowState::windowMode = windowMode;
}

void RType::WindowState::initState() {
    this->splashDone = false;
    this->firstLoadDone = false;
    this->loading = false;
    this->windowMode = IN_LAUNCH;
}

RType::WindowState::~WindowState() = default;
