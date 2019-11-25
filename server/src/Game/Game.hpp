//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_GAME_HPP
#define CPP_RTYPE_2019_GAME_HPP

#include <vector>
#include <string>
#include <iostream>
#include "../Player/Player.hpp"
#include "../Map/Map.hpp"
#include "../Bullet/Bullet.hpp"
#include "../Utils/Utils.hpp"

class Game {
public:
    Game(std::vector<std::string> pseudo);
    ~Game();

    void Launch();
// Fonction update avec en gros en argument la liste des actions effectués par les joueurs et le temps depuis la dernière update
private:
    int currentMap_;
    std::string action_;
    GameState gameState_;


    std::vector<Player *> playerList_;
    std::vector<Map *> mapList_;
    std::vector<Bullet*> bulletList_;
};


#endif //CPP_RTYPE_2019_GAME_HPP