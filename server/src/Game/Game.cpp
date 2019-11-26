//
// Created by glithaud on 11/23/19.
//

#include "Game.hpp"

//AFFICHAGE 24 par 32
//Joueur de taille 0.5 hauteur et 1 en largeur

Game::Game(std::vector<std::string> pseudo) {
    std::string color = "Blue";
    gameState_ = CREATION;
    maxPosX_ = 0;
    currentMap_ = 0;
    mapList_.push_back(new Map(1));
    action_ = mapList_[currentMap_]->getNextAction();
    setActionInfo();
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
    gameState_ = LAUNCHED;
    setPlayer();
}

void Game::Update(std::vector<std::string> commands, float timeSinceUpdate) {
    timeSinceUpdate_ = timeSinceUpdate;
    movePosX();

    /*
     * Diminuer le temps des shots des monstres
     *  et des joueurs TOUS
     */

    //check gameAction



    // Faire les commandes effectuées par les joueurs
    std::vector<std::string> res;
    std::cout << "Command vector :" << std::endl;
    for (int i = 0; (unsigned long)i < commands.size(); i++) {
        std::cout << commands[i] << std::endl;
    }
    std::cout << "End Command Vector" << std::endl;

    for (int i = 0 ; (unsigned long)i < commands.size(); i++) {
        boost::split(res, commands[i], boost::is_any_of(";"));
        for (int j = 0; (unsigned long) j < playerList_.size(); j++) {
            if (playerList_[j]->getPseudo() == res[0] && res[1] == "Move") {
                pMove(i, res[2]);
            }
            else if (playerList_[j]->getPseudo() == res[0] && res[1] == "Shoot") {
                //pShoot();
            }
        }
    }

    //Update les monstres
    /*
     * Mettre à jour la position et tirer si besoin
     */

    //Repositionner les joueurs en dehors de l'écran
    /*
     * Force le joueur à rester sur l'écran par rapport à ou en est dans le niveau
     */

    //Update les balles
    /*
     * Mettre à jour les positions
     * Checker collisions et infliger dégats, mettre à jour score etc si besoin
     */

}

void Game::setPlayer() {
    if (currentMap_ == 0) {
        for (int i = 0; (unsigned long)i < playerList_.size(); i++) {
            playerList_[i]->setPos({2, static_cast<float>((3 * i) + 6)});
        }
    }
}

void Game::setActionInfo() {
    std::vector<std::string> res;
    boost::split(res, action_, boost::is_any_of(";"));
    posAction_ = std::atoi(res[0].c_str());
    typeAction_ = res[1];
    if (typeAction_ == "ADD") {
        typeActionMonster_ = res[2];
        actionY_ = std::atof(res[3].c_str());
    } else if (typeAction_ == "END")
        maxPosX_ = std::atof(res[0].c_str());
}

void Game::movePosX() {
    if (maxPosX_ != 0 && posx_ < (maxPosX_ - 32.1))
        posx_ += (timeSinceUpdate_ / mapList_[currentMap_]->getSpeed());
    else
        posx_ = maxPosX_ - 32;
    std::cout << "---------\nMap Begin x : " << posx_ << std::endl;
}

void Game::pMove(int i, std::string direction) {
    std::cout << playerList_[i]->getPseudo() << " want go to " << direction << std::endl;
    if (playerList_[i]->getPlayerState() == DEAD)
        return;
    Point<float> posWanted = playerList_[i]->getPos();
    Point<float> sizeWanted = playerList_[i]->getSize();
    if (direction == "SOUTH") {
        posWanted.y += 0.5;
    }
    if (direction == "NORTH") {
        posWanted.y -= 0.5;
    }
    if (direction == "EAST") {
        posWanted.x += 0.5;
    }
    if (direction == "WEST") {
        posWanted.x -= 0.5;
    }
    std::cout << "At X : " << posWanted.x << " Y : " << posWanted.y << std::endl;

    //Check collision avec le plafond et mur
    //Hauteur max == 24
    if (posWanted.y - (sizeWanted.y / 2) < (0 + mapList_[currentMap_]->getCollideBot(static_cast<int>(posWanted.x)))) {
        return;
    }
    if (posWanted.y + (sizeWanted.y / 2) > (24 - mapList_[currentMap_]->getCollideTop(static_cast<int>(posWanted.x)))) {
        return;
    }


    Point<float> posOther;
    Point<float> sizeOther;
    //Check collision avec les autres joueurs
    for (int j = 0; (unsigned long) j < playerList_.size(); j++) {
        if (playerList_[j]->getUuid() != playerList_[i]->getUuid()) {
            posOther = playerList_[j]->getPos();
            sizeOther = playerList_[j]->getSize();
            if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
                posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
                posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
                posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
                std::cout << "Ca marche les collisions" << std::endl;
                return;
            }

        }
    }

    //Check collisions avec monstres
    /*
     *
     *
     *
     */

    //Changer coordonnées
    playerList_[i]->setPos(posWanted);
}