//
// Created by glithaud on 11/23/19.
//

#include "Monster.hpp"

Monster::Monster(std::string type, int nbID, float x, float y): type_(type) {
    UUID_ = type + std::to_string(nbID);
    if (type == "bédodo") {
        life_ = 50;
        pos_ = {x, y};
        direction_ = {-1, -0.5};
        shotSpeed_ = 1000;
        timeNextShoot_ = 3000;
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
