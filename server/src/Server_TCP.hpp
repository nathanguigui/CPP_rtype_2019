//
// Created by lcomte on 20/11/2019.
//

#ifndef SERVER_RTYPE_SERVER_TCP_HPP
#define SERVER_RTYPE_SERVER_TCP_HPP
#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <set>
#include <boost/array.hpp>
#include <cstdlib>
#include <cstring>
#include <boost/asio/basic_stream_socket.hpp>
#include <boost/asio/ip/address.hpp>
#include "connection_handler_TCP.hpp"

using namespace boost::asio;
using boost::asio::ip::tcp;
using namespace std;

class connection_manager {
public:
    connection_manager();
    void start(connection_handler_TCP::pointer);
    void stop(connection_handler_TCP::pointer);
    void stop_all();
    std::set<connection_handler_TCP::pointer> connections_;

};


class Server_TCP {
    public:
        Server_TCP(io_service& io_service, string IP_Address);
        ~Server_TCP();
        //Create_UDP_server(string ServerKey);
        void handle_accept(connection_handler_TCP::pointer new_connection, const boost::system::error_code& err);

    private:
        tcp::acceptor acceptor_;
        boost::asio::io_context &io_context_;
        void start_accept();
        connection_manager users_manager_;
        //Server_UDP_Manager manager_udp_;
};


#endif //SERVER_RTYPE_SERVER_TCP_HPP
