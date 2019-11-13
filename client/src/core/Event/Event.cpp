//
// Created by guigui on 11/12/19.
//

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
    }
}
