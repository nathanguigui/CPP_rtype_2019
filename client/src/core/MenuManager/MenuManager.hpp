//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_MENUMANAGER_HPP
#define CPP_RTYPE_2019_MENUMANAGER_HPP


#include "client/src/core/Menus/MainMenu/MainMenu.hpp"
#include "client/src/core/Menus/JoinLobby/JoinLobby.hpp"

namespace RType {
    class MenuManager {
    public:
        /// Default ctor
        MenuManager(WindowState *state, Event *event, sf::RenderWindow *app);

        /// Default dtor
        virtual ~MenuManager();

        /// Draw the apropriate menu
        void draw();

        /// Switch menu
        void switchMenu(MenuType menuType);
    private:
        MainMenu *_mainMenu;
        JoinLobby *_joinLobby;
        WindowState *_state;
        Event *_event;
        sf::RenderWindow *_app;
    };
}


#endif //CPP_RTYPE_2019_MENUMANAGER_HPP
