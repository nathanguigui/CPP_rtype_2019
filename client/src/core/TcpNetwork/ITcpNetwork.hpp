//
// Created by guigui on 11/29/19.
//

#ifndef CPP_RTYPE_2019_ITCPNETWORK_HPP
#define CPP_RTYPE_2019_ITCPNETWORK_HPP

namespace RType {
    class ITcpNetwork {

    public:
    /// Enum for all tcp command
    enum Commands {
        CREATE_LOBBY,
        JOIN_LOBBY,
        READY_LOBBY,
        INFO_LOBBY,
        START_LOBBY
    };
    };
}

#endif //CPP_RTYPE_2019_ITCPNETWORK_HPP
