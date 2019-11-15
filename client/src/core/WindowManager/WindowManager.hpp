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
        const std::string &_name;
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
