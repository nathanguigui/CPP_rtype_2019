//
// Created by guigui on 11/12/19.
//

#include <iostream>
#include "Event.hpp"

RType::Event::Event(WindowManager *parent, sf::RenderWindow *app, WindowState *state) : _parent(parent), _app(app), _windowState(state) {

}

RType::Event::~Event() {

}

void RType::Event::manageEvent() {
    sf::Event evt;
    while (this->_app->pollEvent(evt)) {
        if (evt.type == sf::Event::Closed)
            this->_app->close();
        if (this->_windowState->getWindowMode() == IN_GAME)
            this->manageGameEvent(evt);
        if (this->_windowState->getWindowMode() == IN_MENU)
            this->manageMenuEvent(evt);
    }
}

void RType::Event::manageGameEvent(sf::Event &evt) {
    this->manageDefaultEvent(evt);
}

void RType::Event::manageMenuEvent(sf::Event &evt) {
    this->manageDefaultEvent(evt);
}

void RType::Event::addEventableObject(RType::EventableObject *eventableObject) {
    this->_eventableObjects.push_back(eventableObject);
}

void RType::Event::clearEventableObject() {
    this->_eventableObjects.clear();
}

void RType::Event::manageDefaultEvent(sf::Event &evt) {
    if (evt.type == sf::Event::EventType::KeyReleased)
        for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleKeyReleased();
    if (evt.type == sf::Event::KeyPressed) {
        switch (evt.key.code) {
            case sf::Keyboard::Left :
                for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleLeft();
                break;
            case sf::Keyboard::Right :
                for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleRight();
                break;
            case sf::Keyboard::Up :
                for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleUp();
                break;
            case sf::Keyboard::Down :
                for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleDown();
                break;
            case sf::Keyboard::Enter :
                for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleEnter();
                break;
        }
    }
}
