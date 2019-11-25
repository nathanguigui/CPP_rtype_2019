//
// Created by glithaud on 11/23/19.
//

#include "Game.hpp"

Game::Game(std::vector<std::string> pseudo) {
    std::string color = "Blue";
    gameState_ = CREATION;
    currentMap_ = 0;
    mapList_.push_back(new Map(1));
    action_ = mapList_[currentMap_]->getNextAction();
    for (auto & it : pseudo) {
        playerList_.push_back(new Player(it, color));
        if (color == "Blue")
            color = "Red";
        else if (color == "Red")
            color = "Yellow";
        else if (color == "Yellow")
            color = "Green";
    }
}

Game::~Game() {

}

void Game::Launch() {

}
