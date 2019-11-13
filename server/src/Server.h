//
// Created by Lucas on 11/13/2019.
//

#ifndef CPP_RTYPE_2019_SERVER_H
#define CPP_RTYPE_2019_SERVER_H

#include <iostream>

using namespace std;

class Server {
    public:
        Server(string IP_Server);
        ~Server();
        void Create_Session(string PartyKey);
    private:

};


#endif //CPP_RTYPE_2019_SERVER_H
