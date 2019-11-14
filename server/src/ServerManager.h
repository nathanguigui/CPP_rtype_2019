//
// Created by Lucas on 11/13/2019.
//

#ifndef CPP_RTYPE_2019_SERVERMANAGER_H
#define CPP_RTYPE_2019_SERVERMANAGER_H

#include "Server.h"

class ServerManager {
    public:
        ServerManager();
        ~ServerManager();
        string Create_NewGameSession();
        void Delete_GameSession();
    private:

};


#endif //CPP_RTYPE_2019_SERVERMANAGER_H
