//
// Created by guigui on 11/27/19.
//

#ifndef CPP_RTYPE_2019_ITCPRECEIVER_HPP
#define CPP_RTYPE_2019_ITCPRECEIVER_HPP

#include <string>

namespace RType {

    class ITcpReceiver {
    public:
        enum PacketType {
            LOBBY_CREATE_DONE,
            LOBBY_JOIN_DONE,
            LOBBY_INFO_DONE
        };
        virtual void packetReceived(PacketType type, std::string data) = 0;
    };
}

#endif //CPP_RTYPE_2019_ITCPRECEIVER_HPP
