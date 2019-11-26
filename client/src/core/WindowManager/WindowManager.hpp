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
#include <client/src/core/TcpNetwork/TcpNetwork.hpp>
#include <client/src/core/Menus/JoinLobby/JoinLobby.hpp>
#include "client/src/core/MenuManager/MenuManager.hpp"

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
        /// Classic Game Loop
        void gameLoop();

        /// Call the good display fc
        void display();

        /// Display elements in launch
        void displayInLaunch();

        /// Display elements in menu
        void displayInMenu();

        /// Display elements in game
        void displayInGame();

        /// Name of window
        const std::string &_name;

        /// SFML Window
        sf::RenderWindow *_app{};

        /// Window State
        WindowState *_state{};

        /// Window Event Manager
        Event *_eventManager{};

        /// Window Settings
        Settings *_settings{};

        /// Window SplashScreen
        SplashScreen *_splashScreen{};

        /// Scene Manager
        SceneManager *_sceneManager{};

        /// Loading Scene
        Loading *_loadingScreen{};

        /// Tcp Network for lobby
        TcpNetwork *_tcpNetwork{};

        /// Menu Manager
        MenuManager *_menuManager{};
    };
}


#endif //CPP_RTYPE_2019_WINDOWMANAGER_HPP
