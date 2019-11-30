//
// Created by lcomte on 20/11/2019.
//

#include "Server_TCP.hpp"


std::string convertToString(char* a)
{
    int i;
    std::string s = "";
    for (i = 0; a[i]; i++) {
        s = s + a[i];
    }
    return s;
}

connection_handler_TCP::connection_handler_TCP(boost::asio::io_service &io_service, Server_TCP *server): sock(io_service), server_(server) {
    create_server = false;
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

void connection_handler_TCP::add_username_in_server() {
    std::vector<std::string> buff;
    for (int i = 0; i < server_->getServerManager().size(); i++) {
        if (keypass_server.compare(server_->getServerManager()[i]->getServerKey()) == 0) {
            buff = server_->getServerManager()[i]->getUsername();
            buff.push_back(username_);
            server_->getServerManager()[i]->setUsername(buff);
            return;
        }
    }
}

std::string connection_handler_TCP::get_all_name_in_server() {
    std::string buffer;
    vector<std::string> data;

    for (int i = 0; i < server_->getServerManager().size(); i++) {
        cout << keypass_server << " " << server_->getServerManager()[i]->getServerKey() << endl;
        if (keypass_server == server_->getServerManager()[i]->getServerKey()) {
            data = server_->getServerManager()[i]->getUsername();
            buffer = "USER_CONNECTED: ";
            for (int j = 0; j < data.size(); j++){
                cout << data[j];
                buffer = buffer + data[j];
            }
            buffer = buffer + "€";
            return buffer;
        }
    }
    return "NOBODY";
}

size_t connection_handler_TCP::get_port_from_keypass() {
    for (int i = 0; i < server_->getServerManager().size(); i++) {
        if (server_->getServerManager()[i]->getServerKey() == action.keypass) {
            return server_->getServerManager()[i]->getPort();
        }
    }
}

void connection_handler_TCP::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    string new_data;
    if (!err) {
        cout << data << endl;
        new_data = convertToString(data);
        cout << new_data << endl;
        if (parse_data(new_data) == true) {
            if (action.type == "CREATE") {
                std::cout << "Create UDP SERVER";
                buffer = "CREATE " + action.keypass + " " + server_->getServerIp();
                buffer = buffer + ":";
                buffer = buffer + to_string(server_->getPortUdp());
                buffer = buffer + "€";
                server_->Create_UDP_server(action.keypass);
                add_username_in_server();
                write_data();
            } else if (action.type == "JOIN") {
                buffer = "JOIN" + server_->getServerIp() + ":";
                buffer = buffer + to_string(get_port_from_keypass()) + "€";
                //add_username_in_server();
                //buffer = get_all_name_in_server();
                cout << action.type << " " << action.keypass << endl;
                write_data();
            }
        } else {
            read_data();
        }
    }
}

void connection_handler_TCP::handle_write(const boost::system::error_code &err, size_t bytes_transferred) {
    std::cout << buffer << std::endl;
    read_data();
}

connection_handler_TCP::pointer connection_handler_TCP::create(boost::asio::io_service &io_service, Server_TCP *server) {
    return pointer(new connection_handler_TCP(io_service, server));
}

bool connection_handler_TCP::parse_data(string data) {
    vector<string> tab;
    boost::split(tab, data, boost::is_any_of(" "));
    if ((tab[1] == "CREATE") && tab.size() == 3) {
        action.type = tab[1];
        action.keypass = tab[0] + to_string(server_->getServerManager().size());
        keypass_server = action.keypass;
        setUsername(tab[2]);
        return true;
    }
    if (tab[1] == "JOIN" && tab.size() == 4) {
        action.type = tab[1];
        action.keypass = tab[2];
        keypass_server = tab[2];
        setUsername(tab[3]);
        return true;
    }
    return false;
}

bool connection_handler_TCP::isCreateServer() const {
    return create_server;
}

void connection_handler_TCP::setCreateServer(bool createServer) {
    create_server = createServer;
}

const action_s &connection_handler_TCP::getAction() const {
    return action;
}

void connection_handler_TCP::setAction(const action_s &action) {
    connection_handler_TCP::action = action;
}

const string &connection_handler_TCP::getUsername() const {
    return username_;
}

void connection_handler_TCP::setUsername(const string &username) {
    username_ = username;
}

