//
// Created by guigui on 11/29/19.
//

#ifndef CPP_RTYPE_2019_TIMER_HPP
#define CPP_RTYPE_2019_TIMER_HPP

#include <SFML/Graphics.hpp>
#include "client/src/core/SplashScreen/SplashScreen.hpp"
#include "client/src/core/TcpNetwork/TcpNetwork.hpp"
#include "client/src/core/MenuManager/MenuManager.hpp"
#include "client/src/core/SceneManager/SceneManager.hpp"
#include "client/src/core/UdpNetwork/UdpNetwork.hpp"
#include "client/src/core/WindowManager/IWindowManager.hpp"
#include "client/src/core/WindowState/WindowState.hpp"


namespace RType {
    using namespace RType;

    class Timer : public CoreObject {
    public:
        /// Old ctor deprecated
        Timer(SplashScreen *splashScreen, TcpNetwork *tcpNetwork, MenuManager *menuManager, WindowState *state,
              Event *eventManager, Loading *loadingScreen, LoadScreen *loadScreen, sf::RenderWindow *app,
              SceneManager *sceneManager);

        /// Default ctor
        explicit Timer(IWindowManager *parent, sf::RenderWindow *app);

        /// Default dtor
        virtual ~Timer();

        /// Try refresh
        void refresh();

        /// Refresh Event
        void refreshEvent();

        /// Refresh graphical elements
        void refreshGraphics();

        /// Refresh network
        void refreshNetwork();

    private:

        /// Enum for all timers
        enum TimersType {
            NETWORK,
            GRAPHICS,
            EVENTS
        };

        /// Check for FPS refresh
        bool needRefresh(float FPS, TimersType type);

        /// Refresh SplashScreen
        void refreshSplashScreen();

        /// Refresh Menu
        void refreshMenu();

        /// Refresh Game
        void refreshGame();

        /// SplashScreen
        SplashScreen *_splashScreen;

        /// TcpNetwork
        TcpNetwork *_tcpNetwork;

        /// UdpNetwork
        UdpNetwork *_udpNetwork;

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

        /// SFML graphics clock
        sf::Clock *_graphicsClock;

        /// SFML network clock
        sf::Clock *_networkClock;

        /// SFML event clock
        sf::Clock *_eventClock;

        /// Parent WindowManager
        IWindowManager *_parent;
    };
}


#endif //CPP_RTYPE_2019_TIMER_HPP
