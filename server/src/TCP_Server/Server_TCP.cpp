//
// Created by lcomte on 20/11/2019.
//

#include "Server_TCP.hpp"

Server_TCP::Server_TCP(io_service &io_service, string IP_Address): users_manager_(), io_context_(io_service), acceptor_(io_service, tcp::endpoint(boost::asio::ip::address::from_string(IP_Address), 25565)) {
    cout << IP_Address << endl;
    server_ip_ = IP_Address;
    port_udp = 2000;
    start_accept();
}

Server_TCP::~Server_TCP() {

}

void Server_TCP::start_accept() {
    connection_handler_TCP::pointer new_connection = connection_handler_TCP::create(io_context_, this);
    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&Server_TCP::handle_accept, this, new_connection,
                                   boost::asio::placeholders::error));
}

void Server_TCP::handle_accept(connection_handler_TCP::pointer new_connection, const boost::system::error_code& err)
{
    if (!err)
    {
        users_manager_.start(new_connection);
    }
    start_accept();
}

void Server_TCP::Create_UDP_server(std::string ServerKey) {
    std::vector<std::string> buff;
    buff.push_back(ServerKey);
    auto test = new Server_UDP(io_context_, server_ip_, port_udp, ServerKey, buff);
    std::cout << server_ip_ << ":" << port_udp << std::endl;
    port_udp +=1;
    server_manager_.push_back(test);
}

void Server_TCP::check_create_server() {
    for (const auto& users:users_manager_.connections_) {
        if (users->isCreateServer()) {
            cout << "need to create a server\n";
            users->setCreateServer(false);
            Create_UDP_server(users->getAction().keypass);
        }
    }
}

const string &Server_TCP::getServerIp() const {
    return server_ip_;
}

void Server_TCP::setServerIp(const string &serverIp) {
    server_ip_ = serverIp;
}

const connection_manager_TCP &Server_TCP::getUsersManager() const {
    return users_manager_;
}

void Server_TCP::setUsersManager(const connection_manager_TCP &usersManager) {
    users_manager_ = usersManager;
}

const vector<Server_UDP *> &Server_TCP::getServerManager() const {
    return server_manager_;
}

void Server_TCP::setServerManager(const vector<Server_UDP *> &serverManager) {
    server_manager_ = serverManager;
}

size_t Server_TCP::getPortUdp() const {
    return port_udp;
}

void Server_TCP::setPortUdp(size_t portUdp) {
    port_udp = portUdp;
}
