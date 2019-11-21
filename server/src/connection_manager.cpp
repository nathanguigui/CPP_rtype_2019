//
// Created by lcomte on 20/11/2019.
//

#include "Server_TCP.hpp"

connection_manager::connection_manager()
{
}

void connection_manager::start(connection_handler_TCP::pointer c)
{
    connections_.insert(c);
    c->start();
}

void connection_manager::stop(connection_handler_TCP::pointer c)
{
    connections_.erase(c);
}

void connection_manager::stop_all()
{
    for (auto it:connections_)
        connections_.erase(it);
}


