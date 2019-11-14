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

    private:
        sf::RenderWindow *_app;
        bool splashDone;
        bool firstLoadDone;
        bool loading;
        WindowMode windowMode;
        bool isRunning;
    };
}


#endif //CPP_RTYPE_2019_WINDOWSTATE_HPP
