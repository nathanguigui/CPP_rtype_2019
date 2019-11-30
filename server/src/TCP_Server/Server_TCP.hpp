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
#include "../UDP_Server/Server_UDP.hpp"
#include "../UDP_Server/Server_UDP_Manager.hpp"
using namespace boost::asio;
using boost::asio::ip::tcp;
using namespace std;

class Server_TCP;

struct action_s {
    std::string type;
    std::string keypass;
};

class connection_handler_TCP : public boost::enable_shared_from_this<connection_handler_TCP>{
public:
    typedef boost::shared_ptr<connection_handler_TCP> pointer;
    connection_handler_TCP(boost::asio::io_service& io_service, Server_TCP *);
    static pointer create(boost::asio::io_service& io_service, Server_TCP *);
    tcp::socket& socket(){return sock;}
    void start();
    void write_data();
    void read_data();
    bool parse_data(string);
    void handle_read(const boost::system::error_code& err, size_t bytes_transferred);
    void handle_write(const boost::system::error_code& err, size_t bytes_transferred);
    bool isCreateServer() const;
    void setCreateServer(bool createServer);
    const action_s &getAction() const;
    void setAction(const action_s &action);
    const string &getUsername() const;
    void setUsername(const string &username);
    void add_username_in_server();
    std::string get_all_name_in_server();

private:
    Server_TCP *server_;
    action_s action;
    tcp::socket sock;
    std::string buffer;
    enum { max_length = 8192};
    char *data;
    bool create_server;
    std::string username_;
    std::string keypass_server;
};


class connection_manager_TCP {
public:
    connection_manager_TCP();
    void start(connection_handler_TCP::pointer);
    void stop(connection_handler_TCP::pointer);
    void stop_all();
    std::set<connection_handler_TCP::pointer> connections_;

};


class Server_TCP {
    public:
        Server_TCP(io_service& io_service, string IP_Address);
        ~Server_TCP();
        void Create_UDP_server(string ServerKey);
        void handle_accept(connection_handler_TCP::pointer new_connection, const boost::system::error_code& err);
        void check_create_server();
        const string &getServerIp() const;
        void setServerIp(const string &serverIp);
        const connection_manager_TCP &getUsersManager() const;
        void setUsersManager(const connection_manager_TCP &usersManager);
        const vector<Server_UDP *> &getServerManager() const;
        void setServerManager(const vector<Server_UDP *> &serverManager);

    private:
        size_t port_udp;
        string server_ip_;
        tcp::acceptor acceptor_;
        boost::asio::io_context &io_context_;
        void start_accept();
        connection_manager_TCP users_manager_;
        std::vector<Server_UDP *> server_manager_;

};


#endif //SERVER_RTYPE_SERVER_TCP_HPP
