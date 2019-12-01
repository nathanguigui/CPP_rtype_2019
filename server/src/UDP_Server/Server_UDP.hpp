//
// Created by lcomte on 21/11/2019.
//

#ifndef RTYPE_SERVER_TEST_SERVER_UDP_HPP
#define RTYPE_SERVER_TEST_SERVER_UDP_HPP
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
#include <vector>
#include "../Game/Game.hpp"
#include <chrono>
#include <ctime>
using namespace boost::asio;
using boost::asio::ip::udp;
using namespace std;

class Server_UDP;


class udp_session : public boost::enable_shared_from_this<udp_session> {
public:
    typedef boost::shared_ptr<udp_session> pointer;
    udp_session(Server_UDP *server);
    ~udp_session();
    void start();
    static pointer create(Server_UDP *);
    void send_data();
    void handle_send(const boost::system::error_code &err, size_t bytes_transferred);
    void read_data();
    void handle_read(const boost::system::error_code &err, size_t bytes_transferred);
    void parse_data(std::string);
    udp::endpoint remote_endpoint_;
private:
    enum { max_length = 8192};
    char * data;
    std::string username;
public:
    const string &getUsername() const;

    void setUsername(const string &username);

public:
    char *getData() const;

    void setData(char *data);

    const string &getBuff() const;

    void setBuff(const string &buff);

private:
    std::string buff;
    Server_UDP *server_;
};

class connection_manager_udp {
public:
    connection_manager_udp();
    void start(udp_session::pointer);
    void stop(udp_session::pointer);
    void stop_all();
    std::set<udp_session::pointer> sessions_;

};

class Server_UDP {
    public:
        Server_UDP(io_service &io_service, string IP_Address, size_t port, std::string, std::vector<std::string> buff);
        ~Server_UDP();
        void handle_accept(udp_session::pointer new_connection, const boost::system::error_code& err);
        void send_data(udp_session *player);
        void read_data(udp_session *player);
        void start_game();
        void update_game(std::string);
    private:
        bool isStarted;
public:
    bool isStarted1() const;

    void setIsStarted(bool isStarted);

private:
    void start_accept();
        string server_key_;
public:
    const string &getServerKey() const;

    void setServerKey(const string &serverKey);

    const string &getServerIp() const;

    void setServerIp(const string &serverIp);

    size_t getPort() const;

    void setPort(size_t port);

    vector<std::string> getUsername();

    void setUsername(const vector<std::string> &username);

private:
    string server_ip_;
        size_t port_;
        udp::socket socket_;
        enum { max_length = 8192};
        connection_manager_udp session_manager_;
        char *data;
        std::string message;
        std::vector<std::string> username_;
        std::vector<std::string> command_launch;
        std::chrono::time_point<std::chrono::system_clock> start, end;
        Game game_;
public:
    const Game &getGame() const;

    void setGame(const Game &game);
};


#endif //RTYPE_SERVER_TEST_SERVER_UDP_HPP
