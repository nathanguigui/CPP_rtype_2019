//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_WINDOWSTATE_HPP
#define CPP_RTYPE_2019_WINDOWSTATE_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/CoreObject/CoreObject.hpp"

namespace RType {
    using namespace RType;

    enum WindowMode {
        UNDEFINED,
        IN_LAUNCH,
        IN_MENU,
        IN_GAME
    };

    enum MenuType {
        MENU_MAIN_MENU,
        MENU_LOBBY_MENU,
        MENU_JOIN_LOBBY,
        MENU_SETTINGS
    };

    class WindowState: public CoreObject {
    public:
        explicit WindowState(sf::RenderWindow *app);

        void initState();

        virtual ~WindowState();

        bool isSplashDone() const;

        void setSplashDone(bool splashDone);

        bool isFirstLoadDone() const;

        void setFirstLoadDone(bool firstLoadDone);

        bool isLoading() const;

        void setIsLoading(bool isLoading);

        WindowMode getWindowMode() const;

        void setWindowMode(WindowMode windowMode);

        MenuType getMenuType() const;

        void setMenuType(MenuType menuType);

        void addPlayer(const std::string& name);

        int getPlayerCount();

        bool isLobbyAdmin() const;

        void setIsLobbyAdmin(bool isLobbyAdmin);

        std::string getPlayerName(int playerNb);

    private:
        sf::RenderWindow *_app;
        bool splashDone = false;
        bool firstLoadDone = false;
        bool loading = false;
        WindowMode windowMode{};
        MenuType menuType{};
        bool isRunning{};
        std::vector<std::string> _playerList;
        bool lobbyAdmin = false;
    };
}


#endif //CPP_RTYPE_2019_WINDOWSTATE_HPP
