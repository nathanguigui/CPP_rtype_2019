//
// Created by guigui on 11/30/19.
//

#ifndef CPP_RTYPE_2019_IWINDOWMANAGER_HPP
#define CPP_RTYPE_2019_IWINDOWMANAGER_HPP

#include <client/src/core/CoreObject/CoreObject.hpp>

namespace RType {
    using namespace RType;

    class IWindowManager {
    public:

        /// get Event from WindowManager
        virtual CoreObject *getEvent() = 0;

        /// get Loading from WindowManager
        virtual CoreObject *getLoading() = 0;

        /// get LoadScreen from WindowManager
        virtual CoreObject *getLoadScreen() = 0;

        /// get Logger from WindowManager
        virtual CoreObject *getLogger() = 0;

        /// get SceneManager from WindowManager
        virtual CoreObject *getSceneManager() = 0;

        /// get Settings from WindowManager
        virtual CoreObject *getSettings() = 0;

        /// get SoundManager from WindowManager
        virtual CoreObject *getSoundManager() = 0;

        /// get SplashScreen from WindowManager
        virtual CoreObject *getSplashScreen() = 0;

        /// get WindowState from WindowManager
        virtual CoreObject *getWindowState() = 0;

        /// get Timer from WindowManager
        virtual CoreObject *getTimer() = 0;

        /// get UdpNetwork from WindowManager
        virtual CoreObject *getUdpNetwork() = 0;

        /// get TcpNetwork from WindowManager
        virtual CoreObject *getTcpNetwork() = 0;

        /// get MenuManager from WindowManager
        virtual CoreObject *getMenuManager() = 0;

    private:

    };
}

#endif //CPP_RTYPE_2019_IWINDOWMANAGER_HPP
