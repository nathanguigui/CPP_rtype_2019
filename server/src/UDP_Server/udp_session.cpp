//
// Created by lcomte on 26/11/2019.
//

#include "Server_UDP.hpp"

udp_session::udp_session(Server_UDP *server) : server_(server) {
    data = (char *)malloc(sizeof(char ) * max_length);
}

udp_session::~udp_session() {

}

udp_session::pointer udp_session::create(Server_UDP *server) {
    return pointer(new udp_session(server));
}

void udp_session::send_data() {
    server_->send_data(this);
}

void udp_session::read_data() {
    server_->read_data(this);
}

char *udp_session::getData() const {
    return data;
}

void udp_session::setData(char *data) {
    udp_session::data = data;
}

const string &udp_session::getBuff() const {
    return buff;
}

void udp_session::setBuff(const string &buff) {
    udp_session::buff = buff;
}

void udp_session::handle_send(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {
        read_data();
    }
}

void udp_session::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {
        cout << "Username in UDP server ->" <<data << endl;

    }
}

void udp_session::start() {
    read_data();
}

const string &udp_session::getUsername() const {
    return username;
}

void udp_session::setUsername(const string &username) {
    udp_session::username = username;
}
