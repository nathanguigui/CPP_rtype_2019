//
// Created by glithaud on 11/23/19.
//

#include "Monster.hpp"

Monster::Monster(std::string type, int nbID, float x, float y): type_(type) {
    UUID_ = type + std::to_string(nbID);
    monsterState_ = ALIVE;
    //Little Red
    if (type == "bédodo") {
        // Initialisation de la vie
        life_ = 50;
        // Initialisation du compteur du patterne de déplacement
        currentTravel_ = 0;
        // Poisiton du montre
        pos_ = {x, y};
        // Taille du monstre
        size_ = {1.33,1.35};
        // Type de rocket
        bulletType_ = NORMAL;
        score_ = 200;
        powerUpStyle_ = HEALTH;
        puProba = 7;
        // Vecteurs pour le patterne de déplacement
        std::vector<Point<float> *> move;
        std::vector<int> speed;
        std::vector<int> time;
        // Remplissage patterne de déplacement : move qui correspond à la direction
        move.emplace_back(new Point<float>({-0.5, -1.5}));
        move.emplace_back(new Point<float>({-0.8,0}));
        move.emplace_back(new Point<float>({-0.5, 1.5}));
        move.emplace_back(new Point<float>({-0.8,0}));
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        time.emplace_back(4000);
        time.emplace_back(4000);
        time.emplace_back(4000);
        time.emplace_back(4000);
        travel_.move = move;
        travel_.speed = speed;
        travel_.time = time;
        timeLastTravelChanged_ = travel_.time[currentTravel_];
        shotSpeed_ = 2000;
        timeNextShoot_ = 3000;
    }
    //BOSS ORANGE
    if (type == "Boss1") {
        // Initialisation de la vie
        life_ = 400;
        // Initialisation du compteur du patterne de déplacement
        currentTravel_ = 0;
        // Poisiton du montre
        pos_ = {x, y};
        // Taille du monstre
        size_ = {2,2};
        // Type de rocket
        bulletType_ = BOSSONE;
        score_ = 400;
        powerUpStyle_ = SHOTSPEED;
        puProba = 6;
        // Vecteurs pour le patterne de déplacement
        std::vector<Point<float> *> move;
        std::vector<int> speed;
        std::vector<int> time;
        // Remplissage patterne de déplacement : move qui correspond à la direction
        move.emplace_back(new Point<float>({-0.0, -3}));
        move.emplace_back(new Point<float>({-0.0,3}));
        move.emplace_back(new Point<float>({-0.0, -3}));
        move.emplace_back(new Point<float>({-0.0,3}));
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        travel_.move = move;
        travel_.speed = speed;
        travel_.time = time;
        timeLastTravelChanged_ = travel_.time[currentTravel_];
        shotSpeed_ = 2000;
        timeNextShoot_ = 1000;
    }
    // Little Brown
    if (type == "Grey") {
        // Initialisation de la vie
        life_ = 110;
        // Initialisation du compteur du patterne de déplacement
        currentTravel_ = 0;
        // Poisiton du montre
        pos_ = {x, y};
        // Taille du monstre
        size_ = {1.33,1.35};
        // Type de rocket
        bulletType_ = NORMAL;
        score_ = 150;
        powerUpStyle_ = SHOTSPEED;
        puProba = 6;
        // Vecteurs pour le patterne de déplacement
        std::vector<Point<float> *> move;
        std::vector<int> speed;
        std::vector<int> time;
        // Remplissage patterne de déplacement : move qui correspond à la direction
        move.emplace_back(new Point<float>({0.2, -3}));
        move.emplace_back(new Point<float>({0.2,3}));
        move.emplace_back(new Point<float>({0.2, -3}));
        move.emplace_back(new Point<float>({0.2,3}));
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        travel_.move = move;
        travel_.speed = speed;
        travel_.time = time;
        timeLastTravelChanged_ = travel_.time[currentTravel_];
        shotSpeed_ = 2000;
        timeNextShoot_ = 1000;
    }
    //BOSS VERT
    if (type == "Green") {
        // Initialisation de la vie
        life_ = 600;
        // Initialisation du compteur du patterne de déplacement
        currentTravel_ = 0;
        // Poisiton du montre
        pos_ = {x, y};
        // Taille du monstre
        size_ = {2.6,5.3};
        // Type de rocket
        bulletType_ = BOSSONE;
        score_ = 150;
        powerUpStyle_ = HEALTH;
        puProba = 6;
        // Vecteurs pour le patterne de déplacement
        std::vector<Point<float> *> move;
        std::vector<int> speed;
        std::vector<int> time;
        // Remplissage patterne de déplacement : move qui correspond à la direction
        move.emplace_back(new Point<float>({-0.0, -3}));
        move.emplace_back(new Point<float>({-1.0,3}));
        move.emplace_back(new Point<float>({-0.0, -3}));
        move.emplace_back(new Point<float>({-1.0,3}));
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        speed.emplace_back(1000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        time.emplace_back(5000);
        travel_.move = move;
        travel_.speed = speed;
        travel_.time = time;
        timeLastTravelChanged_ = travel_.time[currentTravel_];
        shotSpeed_ = 2000;
        timeNextShoot_ = 1000;
    }
}

const std::string &Monster::getType() const {
    return type_;
}

void Monster::setType(const std::string &type) {
    type_ = type;
}

const std::string &Monster::getUuid() const {
    return UUID_;
}

void Monster::setUuid(const std::string &uuid) {
    UUID_ = uuid;
}

float Monster::getLife() const {
    return life_;
}

void Monster::setLife(float life) {
    life_ = life;
}

const Point<float> &Monster::getPos() const {
    return pos_;
}

void Monster::setPos(const Point<float> &pos) {
    pos_ = pos;
}

const Point<float> &Monster::getDirection() const {
    return direction_;
}

void Monster::setDirection(const Point<float> &direction) {
    direction_ = direction;
}

float Monster::getSpeed() const {
    return speed_;
}

void Monster::setSpeed(float speed) {
    speed_ = speed;
}

float Monster::getShotSpeed() const {
    return shotSpeed_;
}

void Monster::setShotSpeed(float shotSpeed) {
    shotSpeed_ = shotSpeed;
}

float Monster::getTimeNextShoot() const {
    return timeNextShoot_;
}

void Monster::setTimeNextShoot(float timeNextShoot) {
    timeNextShoot_ = timeNextShoot;
}

Monster::~Monster() {

}

const MPattern &Monster::getTravel() const {
    return travel_;
}

void Monster::setTravel(const MPattern &travel) {
    travel_ = travel;
}

float Monster::getTimeLastTravelChanged() const {
    return timeLastTravelChanged_;
}

void Monster::setTimeLastTravelChanged(float timeLastTravelChanged) {
    timeLastTravelChanged_ = timeLastTravelChanged;
}

int Monster::getCurrentTravel() const {
    return currentTravel_;
}

void Monster::setCurrentTravel(int currentTravel) {
    currentTravel_ = currentTravel;
}

const Point<float> &Monster::getSize() const {
    return size_;
}

void Monster::setSize(const Point<float> &size) {
    size_ = size;
}

BulletType Monster::getBulletType() const {
    return bulletType_;
}

void Monster::setBulletType(BulletType bulletType) {
    bulletType_ = bulletType;
}

ObjectState Monster::getMonsterState() const {
    return monsterState_;
}

void Monster::setMonsterState(ObjectState monsterState) {
    monsterState_ = monsterState;
}

int Monster::getScore() const {
    return score_;
}

void Monster::setScore(int score) {
    score_ = score;
}

PowerUpStyle Monster::getPowerUpStyle() const {
    return powerUpStyle_;
}

int Monster::getPuProba() const {
    return puProba;
}

std::string Monster::getTypeHexa() {
    if (type_ == "bédodo") {
        return "0x620";
    } else if (type_ == "Boss1") {
        return "0x621";
    } else if (type_ == "Grey") {
        return "0x622";
    } else if (type_ == "Green") {
        return "0x623";
    }
    return "";
}
