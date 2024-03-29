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
    mUUID = 0;
    bID_= 0;
    puID = 0;
    posx_ = 0;
    currentMap_ = 0;
    mapList_.push_back(new Map(1));
    mapList_.push_back(new Map(2));
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
    srand (time(NULL));
}

Game::~Game() {

}

void Game::Launch() {
    gameState_ = LAUNCHED;
    setPlayer();
}

std::vector<std::string> Game::Update(std::vector<std::string> commands, float timeSinceUpdate) {
    /*
    * Time since Update en seconde donc à convertir en ms au moment où on connecte avec le serveur
    */
    std::cout << "Posx au début: " << posx_ << std::endl;
    timeSinceUpdate_ = timeSinceUpdate;
    std::cout << "TimeSinceUpdate : " << timeSinceUpdate_ << std::endl;
    data.clear();
    data.emplace_back("0x198$");

    if (!manageGameState()) {
        // Ecrit les données return
        for (int i = 0; (unsigned long)i < data.size(); i++) {
            std::cout << data[i] << std::endl;
        }
        return data;
    }

    movePosX();
    data.emplace_back((std::string) "0x498;0x415;" + std::to_string(currentMap_) + ";" + std::to_string((int)(posx_ * 100)) + "$");

    // Mets à jour le temps de shoot des joueurs et monstres
    updateShotTimer();

    //check gameAction
    std::cout << "PosAction : " << posAction_ << std::endl;
    std::cout << "maxPosX : " << maxPosX_ << std::endl;
    if (static_cast<int>(posx_ + 32) >= posAction_ && typeAction_ != "END") {
        while (static_cast<int>(posx_ + 32) >= posAction_ && typeAction_ != "END")
            makeAction();
    }

    // Faire les commandes effectuées par les joueurs
    std::vector<std::string> res;
    std::cout << "Command vector :" << std::endl;
    for (int i = 0; (unsigned long)i < commands.size(); i++) {
        std::cout << commands[i] << std::endl;
    }
    std::cout << "End Command Vector" << std::endl;

    std::vector<std::string *> tmp;
    for (int j = 0; (unsigned long)j < playerList_.size(); j++) {
        tmp.push_back( new std::string(playerList_[j]->getPseudo()));
        std::cout <<  "TMP : " << tmp[0] << std::endl;
    }

    for (int i = 0; (unsigned long) i < commands.size(); i++) {
        res.clear();
        boost::split(res, commands[i], boost::is_any_of(";"));
        for (int k = 0; (unsigned long) k < playerList_.size(); k++) {
            if ((res[0] == "guigui" || res[0] == "toto" || res[0] == "perceval" || res[0] == "comte")&& res[1] == "Move") {
                pMove(k, res[2]);
            } else if ((res[0] == "guigui" || res[0] == "toto" || res[0] == "perceval" || res[0] == "comte") && res[1] == "Shoot" &&
                       playerList_[k]->getPlayerState() == ALIVE) {
                pShoot(k);
                std::cout << "Shoot" << std::endl;
            }
        }
    }

    //Update les monstres
    std::cout << "There are " << monsterList.size() << " monsters" << std::endl;
    for (int i = 0; (unsigned long)i < monsterList.size(); i++) {
        mMove(i);
        mShoot(i);
        i = mDestroyer(i);
    }

    // Repositionner les joueurs en dehors de l'écran
    pForceMove();

    // Update les balles
    bUpdate();

    // Détruit les balles hits et en dehors de l'écran
    bDestroyer();

    // Détruit les powerups hors de l'écran
    puDestroyer();

    // Tue les montres
    mDead();

    // Ecrit les données à renvoyer
    writeData();

    // Ecrit les données return
    for (int i = 0; (unsigned long)i < data.size(); i++) {
        std::cout << data[i] << std::endl;
    }
    std::cout << "End of update" << std::endl;

    return data;
}

bool Game::manageGameState() {
    bool allDead = true;
    if (gameState_ == LAUNCHED) {
        for (int i = 0; (unsigned long)i < playerList_.size(); i++) {
            if (playerList_[i]->getPlayerState() != DEAD)
                allDead = false;
        }
        if (maxPosX_ != 0 && posx_ == maxPosX_ - 32 && monsterList.empty() && currentMap_ < mapList_.size() - 1) {
            resetGame();
            std::cout << "C WIN AVEC NIVO APRAIENT" << std::endl;
            gameState_ = BETWEENGAME;
            timeToWait_ = 10000;
            data.push_back((std::string)"0x498;0x416;"  + std::to_string(timeToWait_) + "$");
            return false;
        } else if (allDead) {
            std::cout << " C LOOSE" << std::endl;
            gameState_ = ENDGAME;
            timeToWait_ = 10000;
            data.push_back((std::string)"0x498;0x418;" + std::to_string(timeToWait_) + "$");

            return false;
        }  else if (maxPosX_ != 0 && posx_ == maxPosX_ - 32 && monsterList.empty() && currentMap_ >= mapList_.size() - 1) {
            std::cout << "C WIN YA PU DE NIVO DéSO FRAIRE" << std::endl;
            gameState_ = WINGAME;
            timeToWait_ = 10000;
            data.push_back((std::string)"0x498;0x417;"  + std::to_string(timeToWait_) + "$");
            return false;
        } else {
            std::cout << "continue à jouer tranquille" << std::endl;
            return true;
        }
    }
    else if (gameState_ == BETWEENGAME) {
        std::cout << "BetweenGame for " << timeToWait_ << "ms\n";
        timeToWait_ -= timeSinceUpdate_;
        data.push_back((std::string)"0x498;0x416;"  + std::to_string(timeToWait_) + "$");
        if (timeToWait_ <= 0) {
            gameState_ = LAUNCHED;
        }
    }
    else if (gameState_ == ENDGAME) {
        timeToWait_ -= timeSinceUpdate_;
        data.push_back((std::string)"0x498;0x418;" + std::to_string(timeToWait_) + "$");
        std::cout << "Endgame for " << timeToWait_ << "ms\n";
        if (timeToWait_ <= 0) {
            gameState_ = FINISHED;
        }
    }
    else if (gameState_ == WINGAME) {
        timeToWait_ -= timeSinceUpdate_;
        std::cout << "Wingame for " << timeToWait_ << "ms\n";
        data.push_back((std::string)"0x498;0x417;"  + std::to_string(timeToWait_) + "$");
        if (timeToWait_ <= 0) {
            gameState_ = FINISHED;
        }
    }
    else if (gameState_ == FINISHED) {
        /*
         * FINISHED to serveur
         */
        std::cout << "Finished" << std::endl;
    }
    return false;
}

void Game::resetGame() {
    bulletList_.clear();
    currentMap_++;
    maxPosX_ = 0;
    posx_ = 0;
    mUUID = 0;
    bID_ = 0;
    action_ = mapList_[currentMap_]->getNextAction();
    setActionInfo();
    for (int i = 0;(unsigned long)i < playerList_.size(); i++) {
        playerList_[i]->setLife(100);
        playerList_[i]->setPlayerState(ALIVE);
        playerList_[i]->setLastShot(playerList_[i]->getShotSpeed());
    }
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
    if (maxPosX_ == 0 || posx_ < (maxPosX_ - 32.1))
        posx_ += (timeSinceUpdate_ / mapList_[currentMap_]->getSpeed());
    else
        posx_ = maxPosX_ - 32;
    std::cout << "---------\nMap Begin x : " << posx_ << std::endl;
    std::cout << "Map end x : " << posx_ + 32 << std::endl;
}

void Game::pMove(int i, std::string direction) {
    std::cout << playerList_[i]->getPseudo() << " want go to " << direction << std::endl;
    if (playerList_[i]->getPlayerState() == DEAD)
        return;
    Point<float> posWanted = playerList_[i]->getPos();
    Point<float> sizeWanted = playerList_[i]->getSize();
    if (direction == "SOUTH") {
        posWanted.y += 1;
    }
    if (direction == "NORTH") {
        posWanted.y -= 1;
    }
    if (direction == "EAST") {
        posWanted.x += 1;
    }
    if (direction == "WEST") {
        posWanted.x -= 1;
    }
    std::cout << "At X : " << posWanted.x << " Y : " << posWanted.y << std::endl;

    //Check collision avec le plafond et mur
    if (posWanted.y - (sizeWanted.y / 2) < (0 + mapList_[currentMap_]->getCollideBot(static_cast<int>(posWanted.x)))) {
        std::cout << "Collide Bot" << std::endl;
        return;
    }
    //Hauteur max == 24
    if (posWanted.y + (sizeWanted.y / 2) > (24 - mapList_[currentMap_]->getCollideTop(static_cast<int>(posWanted.x)))) {
        std::cout << "Collide Top" << std::endl;
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
                std::cout << "Ca marche les collisions PVP" << std::endl;
                return;
            }

        }
    }
    //Check collisions avec monstres
    for (int j = 0; (unsigned long) j < monsterList.size(); j++) {
        posOther = monsterList[j]->getPos();
        sizeOther = monsterList[j]->getSize();
        if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
            posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
            posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
            posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
            std::cout << "Ca marche les collisions PVM" << std::endl;
            return;
        }
    }
    //Check les collisions avec les powerups
    for (int j = 0; (unsigned long) j < powerUpList_.size(); j++) {
        posOther = powerUpList_[j].pos;
        sizeOther = powerUpList_[j].size;
        if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
            posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
            posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
            posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
            std::cout << "Ca marche les collisions PVU" << std::endl;
            if (powerUpList_[j].style == HEALTH) {
                if (playerList_[i]->getLife() + 30 > 100) {
                    playerList_[i]->setLife(100);
                }
                else {
                    playerList_[i]->setLife(playerList_[i]->getLife() + 30);
                }
            }
            else if (powerUpList_[j].style == SHOTSPEED) {
                if (playerList_[i]->getShotSpeed() - 50 >= 200) {
                    playerList_[i]->setShotSpeed(playerList_[i]->getShotSpeed() - 50);
                }
            }
            powerUpList_.erase(powerUpList_.begin() + j);
            j--;
        }
    }
    std::cout << "PLayer " << playerList_[i]->getPseudo() << " move from " << (playerList_[i]->getPos()).x << ";" << (playerList_[i]->getPos()).y << " to " << posWanted.x << ";" << posWanted.y << std::endl;
    //Changer coordonnées
    playerList_[i]->setPos(posWanted);
}

void Game::pShoot(int i) {
    if (playerList_[i]->getLastShot() >= playerList_[i]->getShotSpeed()) {
        bulletList_.emplace_back(new Bullet(playerList_[i]->getBulletType(), bID_,playerList_[i]->getPseudo() , Teams::Players, {(playerList_[i]->getPos()).x + ((playerList_[i]->getSize()).x) + 1.0f,(playerList_[i]->getPos()).y}));
        bID_++;
        playerList_[i]->setLastShot(0);
    }
}

void Game::pForceMove() {
    for (int i = 0;(unsigned long)i < playerList_.size(); i++) {
        if ((playerList_[i]->getPos()).x < posx_ && playerList_[i]->getPlayerState() == ALIVE) {
            playerList_[i]->setPos({posx_,(playerList_[i]->getPos()).y});
            std::cout << "Force Move" << std::endl;
        }
    }
}

int Game::findMe(std::string UUID) {
    for (int i = 0; (unsigned long)i < playerList_.size(); i++) {
        if (playerList_[i]->getUuid() == UUID) {
            return i;
        }
    }
    return 0;
}

void Game::makeAction() {
    if (typeAction_ == "ADD") {
        monsterList.emplace_back(new Monster(typeActionMonster_, mUUID, posAction_, actionY_));
        //std::cout << "Monster of type " << monsterList[mUUID]->getType() << " spawned at x : " << (monsterList[mUUID]->getPos()).x << " and y : " << (monsterList[mUUID]->getPos()).y << std::endl;
        mUUID++;
    }
    action_ = mapList_[currentMap_]->getNextAction();
    setActionInfo();
}

void Game::mMove(int i) {
    bool collide = false;
    float toX;
    float toY;
    Point<float> posWanted;
    Point<float> sizeWanted;
    Point<float> posOther;
    Point<float> sizeOther;
    MPattern pattern = monsterList[i]->getTravel();
    int currentPattern = monsterList[i]->getCurrentTravel();

    toX = (timeSinceUpdate_ / pattern.speed[currentPattern]) * (pattern.move[currentPattern])->x;
    toY = (timeSinceUpdate_ / pattern.speed[currentPattern]) * (pattern.move[currentPattern])->y;

    posWanted = {(monsterList[i]->getPos()).x + toX, (monsterList[i]->getPos()).y + toY};
    sizeWanted = monsterList[i]->getSize();

    for (int j = 0; (unsigned long)j < monsterList.size(); j++) {
        if (monsterList[i]->getUuid() != monsterList[j]->getUuid()) {
            posOther = monsterList[j]->getPos();
            sizeOther = monsterList[j]->getSize();
            if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
                posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
                posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
                posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
                collide = true;
                std::cout << "Ca marche les collisions MVM" << std::endl;
            }
        }
    }
    for (int j = 0; (unsigned long) j < playerList_.size(); j++) {
        posOther = playerList_[j]->getPos();
        sizeOther = playerList_[j]->getSize();
        if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
            posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
            posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
            posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
            std::cout << "Ca marche les collisions MVP" << std::endl;
            collide = true;
        }
    }

    //Hauteur max == 24
    if (posWanted.y - (sizeWanted.y / 2) < (0 + mapList_[currentMap_]->getCollideBot(static_cast<int>(posWanted.x)))) {
        std::cout << "Ca marche les collisions MVY" << std::endl;
        collide = true;
    }
    if (posWanted.y + (sizeWanted.y / 2) > (24 - mapList_[currentMap_]->getCollideTop(static_cast<int>(posWanted.x)))) {
        std::cout << "Ca marche les collisions MVY-" << std::endl;
        collide = true;
    }

    if (monsterList[i]->getTimeLastTravelChanged() - timeSinceUpdate_ <= 0) {
        if ((monsterList[i]->getTravel()).move.size() == monsterList[i]->getCurrentTravel() + 1) {
            monsterList[i]->setCurrentTravel(0);
            monsterList[i]->setTimeLastTravelChanged((monsterList[i]->getTravel()).time[0]);
        }
        else {
            monsterList[i]->setCurrentTravel(monsterList[i]->getCurrentTravel() + 1);
            monsterList[i]->setTimeLastTravelChanged((monsterList[i]->getTravel()).time[monsterList[i]->getCurrentTravel()]);
        }
    }
    else {
        monsterList[i]->setTimeLastTravelChanged(monsterList[i]->getTimeLastTravelChanged() - timeSinceUpdate_);
    }
    std::cout << "Monster " << monsterList[i]->getUuid() << " from x : " << (monsterList[i]->getPos()).x << " ; " << (monsterList[i]->getPos()).y << " want go to " << posWanted.x << " ; " << posWanted.y << std::endl;
    if (!collide) {
        monsterList[i]->setPos(posWanted);
    }
    std::cout << "Monster timeLastTravelChanged : " << monsterList[i]->getTimeLastTravelChanged() << std::endl;
}

void Game::mShoot(int i) {
    if (monsterList[i]->getTimeNextShoot() <= 0)
    {
        bulletList_.emplace_back(new Bullet(monsterList[i]->getBulletType(), bID_, monsterList[i]->getUuid(), Teams::Monsters, {(monsterList[i]->getPos().x - (monsterList[i]->getSize().x) ),(monsterList[i]->getPos().y)}));
        bID_++;
        monsterList[i]->setTimeNextShoot(monsterList[i]->getShotSpeed());
    }
}

int Game::mDestroyer(int i) {
    if ((monsterList[i]->getPos()).x + ((monsterList[i]->getSize()).x / 2) < posx_) {
        monsterList.erase(monsterList.begin() + i);
        i--;
    }
    return (i);
}

void Game::mDead() {
    for (int i = 0; (unsigned long)i < monsterList.size(); i++) {
        if (monsterList[i]->getMonsterState() == DEAD) {
            monsterList.erase(monsterList.begin() + i);
            i--;
        }
    }
}

void Game::updateShotTimer() {
    for (int i = 0; (unsigned long)i < playerList_.size(); i++) {
        if (playerList_[i]->getPlayerState() == ALIVE)
            playerList_[i]->setLastShot(playerList_[i]->getLastShot() + timeSinceUpdate_);
    }
    for (int i = 0; (unsigned long)i < monsterList.size(); i++) {
        monsterList[i]->setTimeNextShoot(monsterList[i]->getTimeNextShoot() - timeSinceUpdate_);
    }
}

void Game::bUpdate() {
    Point<float> bPos;
    Point<float> bSize;
    Point<float> posWanted;
    Point<float> sizeWanted;
    Point<float> posOther;
    Point<float> sizeOther;
    float toX;
    float toY;
    int victime = 0;
    int it = 0;

    for (int i = 0; (unsigned long) i < bulletList_.size(); i++) {
        bPos = bulletList_[i]->getPos();
        bSize = bulletList_[i]->getSize();

        toX = bPos.x + ((timeSinceUpdate_ / 1000) * (bulletList_[i]->getDirection()).x);
        toY = bPos.y + ((timeSinceUpdate_ / 1000) * (bulletList_[i]->getDirection()).y);

        posWanted = {toX, toY};

        // Bullets des players, de gauche à droite
        if (bulletList_[i]->getTeam() == Teams::Players) {
            posWanted = {bPos.x + ((toX - bPos.x) / 2), bPos.y + ((toY - bPos.y) / 2)};
            sizeWanted = {bSize.x + (toX - bPos.x), bSize.y};
        } //Bullet des monstres, de droite à gauche
        else if (bulletList_[i]->getTeam() == Teams::Monsters) {
            posWanted = {bPos.x - ((toX - bPos.x) / 2), bPos.y - ((toY - bPos.y) / 2)};
            sizeWanted = {bSize.x - (toX - bPos.x), bSize.y};
        }

        //Collision avec les monstres
        for (int j = 0; (unsigned long) j < monsterList.size(); j++) {
            posOther = monsterList[j]->getPos();
            sizeOther = monsterList[j]->getSize();
            if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
                posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
                posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
                posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
                victime = j;
                bulletList_[i]->setHit(true);
                std::cout << "Ca marche les collisions BVM" << std::endl;
            }
        }
        //Collision balle tirée par un monstre sur un monstre
        if (bulletList_[i]->isHit() && bulletList_[i]->getTeam() == Teams::Monsters) {
            if (bulletList_[i]->getFrom() == monsterList[victime]->getUuid()) {
                bulletList_[i]->setHit(false);
            }
        }
            //Collision balle tirée par un joueur vers un monstre
        else if (bulletList_[i]->isHit() && bulletList_[i]->getTeam() == Teams::Players) {
            monsterList[victime]->setLife(monsterList[victime]->getLife() - bulletList_[i]->getDamage());

            if (monsterList[victime]->getLife() <= 0) {
                monsterList[victime]->setMonsterState(DEAD);
                it = findMe(bulletList_[i]->getFrom());
                playerList_[it]->setScore(playerList_[it]->getScore() + monsterList[victime]->getScore());
                playerList_[it]->setEnemyKilled(playerList_[it]->getEnemyKilled() + 1);
                playerList_[it]->setTotalEnemyKilled(playerList_[it]->getTotalEnemyKilled() + 1);
                if (playerList_[it]->getScore() > 1000 && playerList_[it]->getScore() < 1500) {
                    playerList_[it]->setBulletType(FORCEPODONE);
                } else if (playerList_[it]->getScore() > 1500) {
                    playerList_[it]->setBulletType(FORCEPODTWO);
                }
                //Invocation powerup
                if ((rand() % 10 + 1) <= monsterList[victime]->getPuProba()) {
                    powerUpList_.emplace_back(
                            (PowerUp) {"powerup" + std::to_string(puID), {(monsterList[victime]->getPos()).x, (monsterList[victime]->getPos()).y}, {1, 1},
                                       monsterList[victime]->getPowerUpStyle()});
                    puID += 1;
                }
            }
        }

        //Collision avec les joueurs
        if (!bulletList_[i]->isHit()) {
            for (int j = 0; (unsigned long) j < playerList_.size(); j++) {
                posOther = playerList_[j]->getPos();
                sizeOther = playerList_[j]->getSize();
                if (posWanted.x - (sizeWanted.x / 2) < posOther.x + (sizeOther.x / 2) &&
                    posWanted.x + (sizeWanted.x / 2) > posOther.x - (sizeWanted.x / 2) &&
                    posWanted.y - (sizeWanted.y / 2) < posOther.y + (sizeOther.y / 2) &&
                    posWanted.y + (sizeWanted.y / 2) > posOther.y - (sizeWanted.y / 2)) {
                    victime = j;
                    bulletList_[i]->setHit(true);
                    std::cout << playerList_[j]->getUuid() << std::endl;
                    std::cout << playerList_[j]->getLife() << std::endl;

                    std::cout << "Ca marche les collisions BVP" << std::endl;
                }
            }
            std::cout << "2\n";
            //Collision balle d'un joueur vers un joueur
            if (bulletList_[i]->isHit() && bulletList_[i]->getTeam() == Teams::Players) {
                std::cout << "1\n";
                if (bulletList_[i]->getFrom() == playerList_[victime]->getUuid()) {
                    bulletList_[i]->setHit(false);
                }
            }
                //Collision balle d'un monstre vers un joueur
            else if (bulletList_[i]->isHit() && bulletList_[i]->getTeam() == Teams::Monsters) {
                std::cout << "Bullet " << bulletList_[i]->getUuid() << "from " << (bulletList_[i]->getPos()).x << ":"
                          << (bulletList_[i]->getPos()).y << " to " << toX << ";" << toY << " touched "
                          << playerList_[victime]->getUuid() << " at " << (playerList_[victime]->getPos()).x << ":"
                          << (playerList_[victime]->getPos()).y << std::endl;
                std::cout << "SizeWanted : " << sizeWanted.x << ":" << sizeWanted.y << std::endl;
                std::cout << "PosWanted : " << posWanted.x << ":" << posWanted.y << std::endl;
                std::cout << "Life : " << playerList_[victime]->getLife() << std::endl;
                playerList_[victime]->setLife(playerList_[victime]->getLife() - bulletList_[i]->getDamage());
                std::cout << "Life : " << playerList_[victime]->getLife() << std::endl;
                if (playerList_[victime]->getLife() <= 0) {
                    playerList_[victime]->setPlayerState(DEAD);
                    playerList_[victime]->setPos({0, 0});
                    std::cout << "Nous avons malheureusement perdu un joueur au combat DPL" << std::endl;
                }
            }
        }

        //Setpos
        std::cout << "Bullet UUID " << bulletList_[i]->getUuid() << " go from " << (bulletList_[i]->getPos()).x << ":"
                  << (bulletList_[i]->getPos()).y << " to " << toX << ";" << toY << std::endl;
        bulletList_[i]->setPos({toX, toY});
    }
    for (int i = 0; (unsigned long) i < bulletList_.size(); i++) {
        if (bulletList_[i]->isHit())
            data.emplace_back((std::string) "0x598;0x515;" + std::to_string((int)((bulletList_[i]->getPos()).x - posx_) * 100)  + ";" +
                              std::to_string((int)((24 - (bulletList_[i]->getPos()).y) * 100)) + "$");
    }
}

void Game::bDestroyer() {
    for (int i = 0; (unsigned long)i < bulletList_.size(); i++) {
        if (bulletList_[i]->isHit() || (bulletList_[i]->getPos()).x < posx_ || (bulletList_[i]->getPos()).x > (posx_ + 32)) {
            bulletList_.erase(bulletList_.begin() + i);
            i--;
        }
    }
}

void Game::puDestroyer() {
    for (int i = 0; (unsigned long)i < powerUpList_.size(); i++) {
        if (powerUpList_[i].pos.x < posx_) {
            powerUpList_.erase(powerUpList_.begin() + i);
            i--;
        }
    }
}

void Game::writeData() {
    std::string tmp = "0x798;";
    // Player
    for (int i = 0; (unsigned long)i < playerList_.size(); i++) {
        std::cout << "UUID : " << playerList_[i]->getUuid() << std::endl;
        std::cout <<  string_to_hex(playerList_[i]->getPseudo()) << std::endl;
        std::cout << "pseudo : " << playerList_[i]->getPseudo() << std::endl;
        if (playerList_[i]->getPlayerState() == DEAD)
            data.emplace_back("0x698;0x655;" + string_to_hex(playerList_[i]->getUuid()) + ";" + string_to_hex(playerList_[i]->getPseudo()) + ";" + "0x611" + ";" + std::to_string((int)(playerList_[i]->getScore() * 100)) + "$");
        else {
            tmp.append(string_to_hex(playerList_[i]->getUuid()));
            tmp.append(";");
            data.emplace_back("0x698;0x655;" + string_to_hex(playerList_[i]->getUuid()) + ";" + string_to_hex(playerList_[i]->getPseudo()) + ";" + "0x610" + ";" + std::to_string((int)(playerList_[i]->getScore() * 100)) + ";" + std::to_string((int)(playerList_[i]->getLife() * 100)) + ";" + std::to_string((int)(playerList_[i]->getShotSpeed() * 100)) + ";" + std::to_string((int)((playerList_[i]->getPos()).x - posx_) * 100) + ";" + std::to_string((int)((24 -(playerList_[i]->getPos()).y) * 100)) + ";" + playerList_[i]->getForcePod() + "$");
        }
    }

    // Monstres
    for (int i = 0; (unsigned long)i < monsterList.size(); i++) {
        tmp.append(string_to_hex(monsterList[i]->getUuid()));
        tmp.append(";");
        data.emplace_back("0x698;0x656;" + string_to_hex(monsterList[i]->getUuid()) + ";" + monsterList[i]->getTypeHexa() + ";" + std::to_string((int)((monsterList[i]->getPos()).x - posx_) * 100) + ";" + std::to_string((int)((24 - (monsterList[i]->getPos()).y) * 100))  + "$");
    }

    // Bullet
    for (int i = 0; (unsigned long)i < bulletList_.size(); i++) {
        tmp.append(string_to_hex(std::to_string(bulletList_[i]->getUuid())));
        tmp.append(";");
        data.emplace_back("0x698;0x657;" + string_to_hex(std::to_string(bulletList_[i]->getUuid()))  + ";" + bulletList_[i]->getTypeHexa() + ";" + std::to_string((int)((bulletList_[i]->getPos()).x - posx_) * 100) + ";" + std::to_string((int)((24 - (bulletList_[i]->getPos()).y) * 100)) + "$");
    }

    // PowerUp
    for (int i = 0; (unsigned long)i < powerUpList_.size(); i++) {
        tmp.append(powerUpList_[i].UUID);
        tmp.append(";");
        if (powerUpList_[i].style == HEALTH)
            data.emplace_back("0x698;0x658;" + string_to_hex(powerUpList_[i].UUID)+ ";0x640;" + std::to_string((int)(powerUpList_[i].pos.x - posx_) * 100) + ";" + std::to_string((int)((24 - powerUpList_[i].pos.y) * 100)) + "$");
        else if (powerUpList_[i].style == SHOTSPEED)
            data.emplace_back("0x698;0x658;" + string_to_hex(powerUpList_[i].UUID) + ";0x641;" + std::to_string((int)(powerUpList_[i].pos.x - posx_) * 100) + ";" + std::to_string((int)((24 - powerUpList_[i].pos.y) * 100)) + "$");
    }
    data.emplace_back(tmp);
}