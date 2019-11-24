//
// Created by lcomte on 20/11/2019.
//

#ifndef RTYPE_SERVER_TEST_CONNECTION_HANDLER_TCP_HPP
#define RTYPE_SERVER_TEST_CONNECTION_HANDLER_TCP_HPP

#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using boost::asio::ip::tcp;
using namespace std;

class connection_handler_TCP : public boost::enable_shared_from_this<connection_handler_TCP>{
    public:
        typedef boost::shared_ptr<connection_handler_TCP> pointer;
        connection_handler_TCP(boost::asio::io_service& io_service);
        static pointer create(boost::asio::io_service& io_service);
        tcp::socket& socket(){return sock;}
        void start();
        void write_data();
        void read_data();
        void handle_read(const boost::system::error_code& err, size_t bytes_transferred);
        void handle_write(const boost::system::error_code& err, size_t bytes_transferred);
    private:
        tcp::socket sock;
        std::string buffer;
        enum { max_length = 8192};
        char *data;
};


#endif //RTYPE_SERVER_TEST_CONNECTION_HANDLER_TCP_HPP
