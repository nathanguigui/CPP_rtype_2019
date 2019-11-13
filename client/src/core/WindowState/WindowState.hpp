//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_WINDOWSTATE_HPP
#define CPP_RTYPE_2019_WINDOWSTATE_HPP
#include <SFML/Graphics.hpp>

namespace RType {
    using namespace RType;

    enum WindowMode {
        IN_MENU,
        IN_GAME
    };

    class WindowState {
    public:
        explicit WindowState(sf::Window *app);

        virtual ~WindowState();

        bool isSplashDone() const;

        void setSplashDone(bool splashDone);

        bool isFirstLoadDone() const;

        void setFirstLoadDone(bool firstLoadDone);

        bool isLoading1() const;

        void setIsLoading(bool isLoading);

        WindowMode getWindowMode() const;

        void setWindowMode(WindowMode windowMode);

    private:
        sf::Window *_app;
        bool splashDone;
        bool firstLoadDone;
        bool loading;
        WindowMode windowMode;
    };
}


#endif //CPP_RTYPE_2019_WINDOWSTATE_HPP
