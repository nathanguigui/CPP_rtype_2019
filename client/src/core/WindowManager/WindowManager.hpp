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
#include "client/src/game/Menus/MainMenu/MainMenu.hpp"
#include "client/src/core/SceneManager/SceneManager.hpp"
#include "client/src/core/Loading/Loading.hpp"
#include "client/src/core/Exception/Exception.hpp"
#include <boost/algorithm/string.hpp>
#include <client/src/core/UdpNetwork/UdpNetwork.hpp>
#include "client/src/core/TcpNetwork/TcpNetwork.hpp"
#include "client/src/game/Menus/JoinLobby/JoinLobby.hpp"
#include "client/src/core/Timer/Timer.hpp"
#include "client/src/core/MenuManager/MenuManager.hpp"
#include "client/src/core/LoadScreen/LoadScreen.hpp"
#include "IWindowManager.hpp"

namespace RType {
    using namespace RType;

    class WindowManager : public IWindowManager {
    public:
        explicit WindowManager(const std::string &name);
        void processParams(int ac, char **av);
        void init();
        int run();
        ~WindowManager();

    private:
        /// Classic Game Loop
        void gameLoop();

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

        /// Udp Network for lobby
        UdpNetwork *_udpNetwork{};

        /// Menu Manager
        MenuManager *_menuManager{};

        /// Load screen simple
        LoadScreen *_loadScreen;

        /// Timer of the game
        Timer *_gameTimer{};

    public:

        /// get Event from WindowManager
        CoreObject *getEvent() override;

        /// get Loading from WindowManager
        CoreObject *getLoading() override;

        /// get LoadScreen from WindowManager
        CoreObject *getLoadScreen() override;

        /// get Logger from WindowManager
        CoreObject *getLogger() override;

        /// get SceneManager from WindowManager
        CoreObject *getSceneManager() override;

        /// get Settings from WindowManager
        CoreObject *getSettings() override;

        /// get SoundManager from WindowManager
        CoreObject *getSoundManager() override;

        /// get SplashScreen from WindowManager
        CoreObject *getSplashScreen() override;

        /// get WindowState from WindowManager
        CoreObject *getWindowState() override;

        /// get Timer from WindowManager
        CoreObject *getTimer() override;

        /// get UdpNetwork from WindowManager
        CoreObject *getUdpNetwork() override;

        /// get TcpNetwork from WindowManager
        CoreObject *getTcpNetwork() override;

        /// get MenuManager from WindowManager
        CoreObject *getMenuManager() override;
    };
}


#endif //CPP_RTYPE_2019_WINDOWMANAGER_HPP
