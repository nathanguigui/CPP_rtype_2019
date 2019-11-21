//
// Created by lcomte on 20/11/2019.
//

#include "connection_handler_TCP.hpp"


std::string convertToString(char* a)
{
    int i;
    std::string s = "";
    for (i = 0; a[i]; i++) {
        s = s + a[i];
    }
    return s;
}

connection_handler_TCP::connection_handler_TCP(boost::asio::io_service &io_service): sock(io_service) {
    data = (char *)malloc(sizeof(char ) * max_length);
    boost::asio::ip::tcp::no_delay option(true);

    boost::system::error_code ec;
    sock.set_option(option, ec);
    if (ec)
    {
        // An error occurred.
    }
}

void connection_handler_TCP::start() {
    read_data();
}

void connection_handler_TCP::write_data() {
    sock.async_write_some(
            boost::asio::buffer(buffer, max_length),
            boost::bind(&connection_handler_TCP::handle_write,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void connection_handler_TCP::read_data() {
    sock.async_read_some(
            boost::asio::buffer(data, max_length),
            boost::bind(&connection_handler_TCP::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void connection_handler_TCP::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    std::string new_data;
    if (!err) {
        new_data = convertToString(data);
        cout << new_data << std::endl;
        buffer = "wesh\r\n";
        write_data();
    }
}

void connection_handler_TCP::handle_write(const boost::system::error_code &err, size_t bytes_transferred) {
    std::cout << buffer << std::endl;
    start();
}

connection_handler_TCP::pointer connection_handler_TCP::create(boost::asio::io_service &io_service) {
    return pointer(new connection_handler_TCP(io_service));
}
