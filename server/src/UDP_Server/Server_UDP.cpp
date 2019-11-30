//
// Created by lcomte on 21/11/2019.
//

#include "Server_UDP.hpp"

Server_UDP::Server_UDP(io_service &io_service, string IP_Address, size_t port, std::string keypass) : socket_(io_service, udp::endpoint(boost::asio::ip::address::from_string(IP_Address), port)){
    server_key_ = keypass;
    server_ip_= IP_Address;
    port_ = port;
    data = (char *) malloc(sizeof(char) * max_length);
    start_accept();
}

Server_UDP::~Server_UDP() {

}

void Server_UDP::start_accept() {
    udp_session::pointer new_connection = udp_session::create(this);
    socket_.async_receive(boost::asio::buffer(data, max_length), boost::bind(&Server_UDP::handle_accept, this, new_connection, boost::asio::placeholders::error));
}

void Server_UDP::handle_accept(udp_session::pointer new_connection, const boost::system::error_code &err) {
    if (!err) {
        if (session_manager_.sessions_.size() < 4) {
            cout << data << endl;
            cout << "new_sessions\n";
            session_manager_.start(new_connection);
        }
    } if (session_manager_.sessions_.size() >= 4) {
        cout << "launch game\n";
    }
    start_accept();
}

void Server_UDP::send_data(udp_session *player) {
    socket_.async_send_to(boost::asio::buffer(player->getBuff()), player->remote_endpoint_, boost::bind(&udp_session::handle_send, player, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Server_UDP::read_data(udp_session *player) {
    socket_.async_receive_from(boost::asio::buffer(player->getData(), max_length), player->remote_endpoint_, boost::bind(&udp_session::handle_read, player, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

const string &Server_UDP::getServerKey() const {
    return server_key_;
}

void Server_UDP::setServerKey(const string &serverKey) {
    server_key_ = serverKey;
}

const string &Server_UDP::getServerIp() const {
    return server_ip_;
}

void Server_UDP::setServerIp(const string &serverIp) {
    server_ip_ = serverIp;
}

size_t Server_UDP::getPort() const {
    return port_;
}

void Server_UDP::setPort(size_t port) {
    port_ = port;
}

std::vector<std::string> Server_UDP::getUsername() {
    return username_;
}

void Server_UDP::setUsername(const vector<std::string> &username) {
    username_ = username;
}
