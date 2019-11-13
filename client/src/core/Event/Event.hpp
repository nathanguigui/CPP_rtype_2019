//
// Created by guigui on 11/12/19.
//

#ifndef CPP_RTYPE_2019_EVENT_HPP
#define CPP_RTYPE_2019_EVENT_HPP
#include <SFML/Graphics.hpp>


namespace RType {
    using namespace RType;
    class WindowManager;

    class Event {
    public:
        Event(WindowManager *parent, sf::RenderWindow *app);
        ~Event();
        void manageEvent();

    private:
        WindowManager *_parent;
        sf::RenderWindow *_app;
    };
}


#endif //CPP_RTYPE_2019_EVENT_HPP
