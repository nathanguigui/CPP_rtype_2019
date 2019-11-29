//
// Created by guigui on 11/29/19.
//

#ifndef CPP_RTYPE_2019_SETTINGSMENU_HPP
#define CPP_RTYPE_2019_SETTINGSMENU_HPP


#include <SFML/Graphics.hpp>
#include "client/src/core/Settings/Settings.hpp"
#include "client/src/core/MenuManager/IMenuManager.hpp"
#include "client/src/core/Menus/IMenu/IMenu.hpp"
#include "client/src/core/Gui/Tools.hpp"
#include "../../../core/SoundManager/SoundManager.hpp"

namespace RType {
    using namespace RType;


    class SettingsMenu : public IMenu {

    public:
        SettingsMenu(sf::RenderWindow *app, IMenuManager *parent, Settings *settings);

        virtual ~SettingsMenu();

        void handleLeft() override;
        void handleRight() override;
        void handleUp() override;
        void handleDown() override;
        void handleEnter() override;
        void handleKeyReleased() override;
        void draw() override;
        void handleText(sf::Event &evt) override;

    private:

        SoundManager *_soundmanager;

        enum SettingsMenuStatus {
            QUIT_BUTTON,
            VOLUME_BAR
        };

        /// Set position for all drawable elements
        void initGUI();

        void updateState();

        bool keyReleased;

        sf::Texture *_backgroundTexture;

        sf::Sprite *_backgroundSprite;

        sf::Font *_font;

        sf::Text *_volumeBar[100]{};

        sf::Text *_quitText;

        int _volume = 100;

        SettingsMenuStatus _status;

        sf::RenderWindow *_app;

        IMenuManager *_parent;

        Settings *_settings;

    };
}


#endif //CPP_RTYPE_2019_SETTINGSMENU_HPP
