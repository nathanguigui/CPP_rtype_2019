//
// Created by lcomte on 21/11/2019.
//

#include "Server_UDP.hpp"
#include <math.h>
#include <unistd.h>
std::string hex_to_string(const std::string& input);
std::string string_to_hex(const std::string& input);

Server_UDP::Server_UDP(io_service &io_service, string IP_Address, size_t port, std::string keypass, std::vector<std::string> buff) : socket_(io_service, udp::endpoint(boost::asio::ip::address::from_string(IP_Address), port)), game_(buff){
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

std::vector<std::string> Server_UDP::remove_endline_on_all_line() {
    std::vector<std::string> buff;
    for (int i = 0; i < username_.size(); i++) {
        buff.push_back(username_[i].erase(username_[i].size() - 1));
    }
    return buff;
}

void Server_UDP::start_game() {
    inGame = true;
    username_ = remove_endline_on_all_line();
    cout << "Start New Game and set game start\n";
    Game game(username_);
    setGame(game);
    start = std::chrono::system_clock::now();
    game_.Launch();
    update_game("");
}

void Server_UDP::update_game(std::string received) {
    std::string new_data;
    cout << "WHat i have received-> "<< received << endl;
    end = std::chrono::system_clock::now();
    long elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::string buffer;
    std::vector<std::string> rcv;
    std::vector<std::string> snd;
    cout << "time elapsed: " << elapsed_time << endl;
    boost::split(rcv, received, boost::is_any_of(" "));
    if (isStarted1()) {
        if (rcv[0] == "UPDATE") {
            rcv.clear();
            rcv.push_back("");
            snd = game_.Update(rcv, (float) elapsed_time);
            if (snd.size() == 1) {
                setIsStarted(false);
            }
            for (int i = 0; i < snd.size(); i++) {
                buffer = buffer + snd[i];
            }
            buffer = buffer + "\r\n";
            for (auto it:session_manager_.sessions_) {
                it->setBuff(buffer);
                start = std::chrono::system_clock::now();
                it->send_data();
            }
        } else {
            for (int i = 0; i< rcv.size(); i++) {
                cout << "data received ->";
                cout << rcv[i] << endl;
            }
            //parse data to transfer different action
            std::vector<std::string> parse_rcv = parse_packages(rcv);
            for (int i = 0; i< parse_rcv.size(); i++) {
                cout << "data received ->";
                cout << parse_rcv[i] << endl;
            }
            snd = game_.Update(parse_rcv, (float) elapsed_time);
            if (snd.size() == 1) {
                setIsStarted(false);
            }
            for (int i = 0; i < snd.size(); i++) {
                buffer = buffer + snd[i];
            }
            buffer = buffer + "\r\n";
            for (auto it:session_manager_.sessions_) {
                it->setBuff(buffer);
                start = std::chrono::system_clock::now();
                it->send_data();
            }
        }
    }
}

std::vector<std::string> Server_UDP::parse_packages(std::vector<std::string> recv) {
    std::vector<std::string> buff;
    std::string data;
    for (int i = 0; i < recv.size(); i++) {
        if (recv[i] == "Move" && i + 1 < recv.size()) {
            data = recv[i - 1] + ";" + recv[i] + ";" + recv[i + 1];
            buff.push_back(data);
        } if (recv[i] == "Shoot") {
            data = recv[i - 1] + ";" + recv[i];
            buff.push_back(data);
        }
    }
    return buff;
}

void Server_UDP::handle_accept(udp_session::pointer new_connection, const boost::system::error_code &err) {
    if (!err) {
        if (session_manager_.sessions_.size() < 4 && isStarted == false) {
            session_manager_.start(new_connection);
        }
    } if (session_manager_.sessions_.size() >= 4 || (isStarted == true && inGame != true)) {
        start_game();
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

const Game &Server_UDP::getGame() const {
    return game_;
}

void Server_UDP::setGame(const Game &game) {
    game_ = game;
}

bool Server_UDP::isStarted1() const {
    return isStarted;
}

void Server_UDP::setIsStarted(bool isStarted) {
    Server_UDP::isStarted = isStarted;
}
