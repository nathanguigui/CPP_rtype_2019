//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_MAINMENU_HPP
#define CPP_RTYPE_2019_MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "client/src/core/EventableObject/EventableObject.hpp"

namespace RType {
    using namespace RType;
    class MainMenu : EventableObject {
    public:
        explicit MainMenu(sf::RenderWindow *app);
        virtual ~MainMenu();
        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void draw();

    private:
        sf::RenderWindow *_app;
    };
}


#endif //CPP_RTYPE_2019_MAINMENU_HPP
