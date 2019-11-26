//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_MAINMENU_HPP
#define CPP_RTYPE_2019_MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "client/src/core/Menus/IMenu/IMenu.hpp"
#include "client/src/core/EventableObject/EventableObject.hpp"
#include "client/src/core/Gui/Tools.hpp"
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/Event/Event.hpp"

namespace RType {
    using namespace RType;
    enum MainMenuItemStatus {
        MAIN_MENU_NEW_GAME,
        MAIN_MENU_JOIN_GAME,
        MAIN_MENU_QUIT_GAME
    };
    class MainMenu : IMenu {
    public:
        MainMenu(sf::RenderWindow *app, WindowState *state);
        virtual ~MainMenu();
        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
        void draw() override;
        void handleText(sf::Event &evt) override;

    private:
        void updateState();
        void initGUI();
        sf::RenderWindow *_app;
        sf::Texture *_backgroundTexture;
        sf::Sprite *_backgroundSprite;
        sf::Font *_font;
        sf::Text *_joinText;
        sf::Text *_newText;
        sf::Text *_quitText;
        MainMenuItemStatus _itemStatus;
        bool keyReleased;
        bool _disabled = false;
        WindowState *_state;
    };
}


#endif //CPP_RTYPE_2019_MAINMENU_HPP
