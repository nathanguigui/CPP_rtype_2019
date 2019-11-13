//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SETTINGS_HPP
#define CPP_RTYPE_2019_SETTINGS_HPP

#include <string>
#include "client/src/core/WindowState/WindowState.hpp"

namespace RType {
    using namespace RType;
    class Settings {
    public:
        Settings(WindowState *state);
        virtual ~Settings();

        int getServerPort() const;

        void setServerPort(int serverPort);

        const std::string &getServerIp() const;

        void setServerIp(const std::string &serverIp);

    private:
        int serverPort{};
        std::string serverIp;
        WindowState *_windowState;
    };
}


#endif //CPP_RTYPE_2019_SETTINGS_HPP
