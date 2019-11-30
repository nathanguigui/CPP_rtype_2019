//
// Created by guigui on 11/30/19.
//

#ifndef CPP_RTYPE_2019_IUDPNETWORK_HPP
#define CPP_RTYPE_2019_IUDPNETWORK_HPP

#include <string>
#include <client/src/core/CoreObject/CoreObject.hpp>

namespace RType {
    class IUdpNetwork : public CoreObject {
    public:

        virtual void setDestPort(unsigned short destPort) = 0;

        /// Send Data to socket
        virtual void sendData(const std::string &data) = 0;
    };
}

#endif //CPP_RTYPE_2019_IUDPNETWORK_HPP
