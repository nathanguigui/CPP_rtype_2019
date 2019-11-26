//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_JOINLOBBY_HPP
#define CPP_RTYPE_2019_JOINLOBBY_HPP

#include <SFML/Graphics.hpp>
#include <client/src/core/MenuManager/IMenuManager.hpp>
#include "client/src/core/Menus/IMenu/IMenu.hpp"
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/Gui/Tools.hpp"

namespace RType {
    using namespace RType;

    enum JoinLobbyStatus {
        JOIN_LOBBY_JOIN,
        JOIN_LOBBY_EXIT
    };

    class JoinLobby : public IMenu {
    public:

        /// Default ctor
        JoinLobby(sf::RenderWindow *app, RType::WindowState *state, IMenuManager *parent);

        /// Default dtor
        virtual ~JoinLobby();

        /// Init gui element postion
        void initGUI();

        /// Update color of text depending of state
        void updateState();

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

        /// Join text as button
        sf::Text *_joinText;

        /// Quit text as button
        sf::Text *_quitText;

        /// Status for selected elements
        JoinLobbyStatus  _lobbyStatus;

        /// Text of input field
        sf::Text *_textField;

        /// String of text
        sf::String *_string;

        bool keyReleased;

        /// Window state
        WindowState *_state;

        /// Parent Menu Manager
        IMenuManager *_parent;
    };
}


#endif //CPP_RTYPE_2019_JOINLOBBY_HPP
