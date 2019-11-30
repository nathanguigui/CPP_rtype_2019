//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SETTINGS_HPP
#define CPP_RTYPE_2019_SETTINGS_HPP

#include <string>
#include "client/src/core/WindowState/WindowState.hpp"
#include "client/src/core/CoreObject/CoreObject.hpp"
#include <client/src/core/Exception/Exception.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>

namespace RType {
    using namespace RType;
    class Settings: public CoreObject {
    public:
        Settings(WindowState *state);
        virtual ~Settings();

        /// Check ip args validity
        void checkIp(char *ip);

        /// Check port args validity
        void checkPort(char *port);

        /// Check username args validity
        void checkUsername(char *username);

        /// Debug processed args
        void debugArgs();

        std::string *getPlayerName() const;

        std::string *getLobbyServerIp() const;

        unsigned short getLobbyServerPort() const;

        std::string *getLobbyCode() const;

        void setLobbyCode(std::string *lobbyCode);

        int getSoundVolume() const;

        void setSoundVolume(int soundVolume);

        unsigned short getGameServerPort() const;

        void setGameServerPort(unsigned short gameServerPort);

        void setGameServerPort(const char *gameServerPort);

    private:
        /// Lobby player username
        std::string *_playerName{};

        /// Lobby server Ip
        std::string *_lobbyServerIp{};

        /// Lobby server Port
        unsigned short _lobbyServerPort{};

        /// Game server Port
        unsigned short _gameServerPort{};

        /// Window State
        WindowState *_windowState;

        /// Lobby Code
        std::string *_lobbyCode{};

        /// Sound volume
        int _soundVolume = 100;
    };
}


#endif //CPP_RTYPE_2019_SETTINGS_HPP
