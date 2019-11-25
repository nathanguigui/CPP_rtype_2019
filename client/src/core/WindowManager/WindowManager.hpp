//
// Created by guigui on 11/12/19.
//

#ifndef CPP_RTYPE_2019_WINDOWMANAGER_HPP
#define CPP_RTYPE_2019_WINDOWMANAGER_HPP
#include <SFML/Graphics.hpp>

#include <iostream>
#include "client/src/core/core.hpp"
#include "client/src/core/Event/Event.hpp"
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/Settings/Settings.hpp"
#include "client/src/core/SplashScreen/SplashScreen.hpp"
#include "client/src/core/Menus/MainMenu/MainMenu.hpp"
#include "client/src/core/SceneManager/SceneManager.hpp"
#include "client/src/core/Loading/Loading.hpp"
#include "client/src/core/Exception/Exception.hpp"
#include <boost/algorithm/string.hpp>

namespace RType {
    using namespace RType;
    class WindowManager {
    public:
        explicit WindowManager(const std::string &name);
        void processParams(int ac, char **av);
        void init();
        int run();
        ~WindowManager();

    private:
        void gameLoop();
        void display();
        void displayInLaunch();
        void displayInMenu();
        void displayInGame();

        /// Check ip args validity
        void checkIp(char *ip);

        /// Check port args validity
        void checkPort(char *port);

        /// Check username args validity
        void checkUsername(char *username);

        /// Name of window
        const std::string &_name;

        /// Lobby player username
        std::string *_playerName;

        /// Lobby server Ip
        std::string *_serverIp;

        /// Lobby server Port
        unsigned short _serverPort{};

        sf::RenderWindow *_app{};
        WindowState *_state{};
        Event *_eventManager{};
        Settings *_settings{};
        SplashScreen *_splashScreen{};
        MainMenu *_mainMenu{};
        SceneManager *_sceneManager{};
        Loading *_loadingScreen;
    };
}


#endif //CPP_RTYPE_2019_WINDOWMANAGER_HPP
