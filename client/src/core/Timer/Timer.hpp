//
// Created by guigui on 11/29/19.
//

#ifndef CPP_RTYPE_2019_TIMER_HPP
#define CPP_RTYPE_2019_TIMER_HPP

#include <SFML/Graphics.hpp>
#include <client/src/core/SplashScreen/SplashScreen.hpp>
#include <client/src/core/TcpNetwork/TcpNetwork.hpp>
#include <client/src/core/MenuManager/MenuManager.hpp>
#include <client/src/core/SceneManager/SceneManager.hpp>
#include "client/src/core/WindowState/WindowState.hpp"


namespace RType {
    using namespace RType;

    class Timer {
    public:
        /// Default ctor
        Timer(SplashScreen *splashScreen, TcpNetwork *tcpNetwork, MenuManager *menuManager, WindowState *state,
              Event *eventManager, Loading *loadingScreen, LoadScreen *loadScreen, sf::RenderWindow *app);

        /// Default dtor
        virtual ~Timer();

        /// Try refresh
        void refresh();

    private:

        /// Refresh graphical elements
        void refreshGraphics();

        /// Refresh SplashScreen
        void refreshSplashScreen();

        /// Refresh Menu
        void refreshMenu();

        /// Refresh Game
        void refreshGame();

        /// Refresh Event
        void refreshEvent();

        /// SplashScreen
        SplashScreen *_splashScreen;

        /// TcpNetwork
        TcpNetwork *_tcpNetwork;

        /// MenuManager
        MenuManager *_menuManager;

        /// WindowState
        WindowState *_state;

        /// Event manager
        Event *_eventManager;

        /// SceneManager
        SceneManager *_sceneManager;

        /// Loading Scene
        Loading *_loadingScreen;

        /// LoadScreen simple
        LoadScreen *_loadScreen;

        /// SFML app
        sf::RenderWindow *_app;

        /// SFML clock
        sf::Clock *_clock;

        /// Last refresh
        sf::Time _lastRefresh;
    };
}


#endif //CPP_RTYPE_2019_TIMER_HPP
