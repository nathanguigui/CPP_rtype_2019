//
// Created by guigui on 11/29/19.
//

#ifndef CPP_RTYPE_2019_LOBBY_HPP
#define CPP_RTYPE_2019_LOBBY_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include <client/src/core/WindowState/WindowState.hpp>
#include <client/src/core/MenuManager/IMenuManager.hpp>
#include "client/src/core/Menus/IMenu/IMenu.hpp"
#include <client/src/core/Gui/Tools.hpp>
#include "client/src/core/Settings/Settings.hpp"

namespace RType {
    using namespace RType;

    class Lobby : public IMenu {
    public:

        /// Default ctor
        Lobby(sf::RenderWindow *app, WindowState *state, IMenuManager *parent, Settings *settings);

        /// Default dtor
        virtual ~Lobby();

        /// Init gui elements
        void initGUI();

        /// Update code
        void updateCode();

        /// Update player names
        void updatePlayerNames();

        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
        void draw() override;
        void handleText(sf::Event &evt) override;
    private:
        /// SFML Window
        sf::RenderWindow *_app;

        /// Background texture
        sf::Texture *_backgroundTexture;

        /// Background sprite
        sf::Sprite *_backgroundSprite;

        /// Global Font
        sf::Font *_font;

        /// Start text as button
        sf::Text *_startText;

        /// Code text
        sf::Text *_codeText;

        /// Player one text
        sf::Text *_playerOneText;

        /// Player two text
        sf::Text *_playerTwoText;

        /// Player three text
        sf::Text *_playerThreeText;

        /// Player four text
        sf::Text *_playerFourText;

        bool keyReleased;

        /// Window state
        WindowState *_state;

        /// Parent Menu Manager
        IMenuManager *_parent;

        /// Window settings
        Settings *_settings;
    };
}


#endif //CPP_RTYPE_2019_LOBBY_HPP
