//
// Created by lcomte on 20/11/2019.
//

#include "Server_TCP.hpp"

Server_TCP::Server_TCP(io_service &io_service, string IP_Address): users_manager_(), io_context_(io_service), acceptor_(io_service, tcp::endpoint(boost::asio::ip::address::from_string(IP_Address), 2424)) {
    cout << IP_Address << endl;
    start_accept();
}

Server_TCP::~Server_TCP() {

}

void Server_TCP::start_accept() {
    connection_handler_TCP::pointer new_connection = connection_handler_TCP::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&Server_TCP::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
}

void Server_TCP::handle_accept(connection_handler_TCP::pointer new_connection, const boost::system::error_code& err)
{
    if (!err)
    {
        cout << "salut\n";
        users_manager_.start(new_connection);
    }
    start_accept();
}