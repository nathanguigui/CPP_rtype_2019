//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_SETTINGS_HPP
#define CPP_RTYPE_2019_SETTINGS_HPP

#include <string>

namespace RType {
    class Settings {
    public:
        Settings();
        virtual ~Settings();

        int getServerPort() const;

        void setServerPort(int serverPort);

        const std::string &getServerIp() const;

        void setServerIp(const std::string &serverIp);

    private:
        int serverPort{};
        std::string serverIp;
    };
}


#endif //CPP_RTYPE_2019_SETTINGS_HPP
