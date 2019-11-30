//
// Created by lcomte on 20/11/2019.
//

#include "TCP_Server/Server_TCP.hpp"
#include "UDP_Server/Server_UDP.hpp"

connection_manager_TCP::connection_manager_TCP()
{
}

void connection_manager_TCP::start(connection_handler_TCP::pointer c)
{
    connections_.insert(c);
    c->start();
}

void connection_manager_TCP::stop(connection_handler_TCP::pointer c)
{
    connections_.erase(c);
}

void connection_manager_TCP::stop_all()
{
    for (auto it:connections_)
        connections_.erase(it);
}


connection_manager_udp::connection_manager_udp()
{
}

void connection_manager_udp::start(udp_session::pointer c)
{
    sessions_.insert(c);
    c->start();
}

void connection_manager_udp::stop(udp_session::pointer c)
{
    sessions_.erase(c);
}

void connection_manager_udp::stop_all()
{
    for (auto it:sessions_)
        sessions_.erase(it);
}