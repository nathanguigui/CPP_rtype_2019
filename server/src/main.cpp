//
// Created by lcomte on 20/11/2019.
//

#include "TCP_Server/Server_TCP.hpp"

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;
        Server_TCP server(io_service, argv[1]);
        io_service.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
