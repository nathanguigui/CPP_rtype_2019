//
// Created by guigui on 11/12/19.
//

#include "Event.hpp"

RType::Event::Event(WindowManager *parent, sf::RenderWindow *app) : _parent(parent), _app(app) {

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
