//
// Created by Lucas on 11/13/2019.
//

#ifndef CPP_RTYPE_2019_GAMEMANAGER_H
#define CPP_RTYPE_2019_GAMEMANAGER_H

#include "ServerManager.h"

class GameManager {
    public:
        GameManager();
        ~GameManager();
        void add_User(string username);
        void delete_User(string username);
    private:

};


#endif //CPP_RTYPE_2019_GAMEMANAGER_H
