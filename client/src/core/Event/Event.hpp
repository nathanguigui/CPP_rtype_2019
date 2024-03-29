//
// Created by guigui on 11/12/19.
//

#ifndef CPP_RTYPE_2019_EVENT_HPP
#define CPP_RTYPE_2019_EVENT_HPP
#include <SFML/Graphics.hpp>
#include <client/src/core/Menus/IMenu/IMenu.hpp>
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/EventableObject/EventableObject.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"

namespace RType {
    using namespace RType;
    class WindowManager;

    class Event: public CoreObject {
    public:
        Event(WindowManager *parent, sf::RenderWindow *app, WindowState *state);
        void addEventableObject(EventableObject *eventableObject);
        void clearEventableObject();
        ~Event();
        void manageEvent();

        void setCurrentMenu(IMenu *currentMenu);

        void removeCurrentMenu();

    private:
        void manageDefaultEvent(sf::Event &evt);
        void manageGameEvent(sf::Event &evt);
        void manageMenuEvent(sf::Event &evt);
        WindowManager *_parent;
        sf::RenderWindow *_app;
        WindowState *_windowState;
        std::vector<EventableObject*> _eventableObjects;
        IMenu *_currentMenu = nullptr;
    };
}


#endif //CPP_RTYPE_2019_EVENT_HPP
