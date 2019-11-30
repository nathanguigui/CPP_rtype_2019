//
// Created by glithaud on 11/23/19.
//

#include "Bullet.hpp"

Bullet::Bullet(BulletType type, int UUID, std::string from, Teams teams, Point<float> pos): type_(type), UUID_(UUID), from_(from), team_(teams), pos_(pos) {
    if (type == NORMAL && teams == Players) {
        damage_ = 20;
        direction_ = {3,0};
        size_ = {0.3, 0.3};
    }
    else if (type == NORMAL && teams == Monsters) {
        damage_ = 30;
        direction_ = {-3,0};
        size_ = {0.3, 0.2};
    } else if (type == FORCEPODONE && teams == Players) {
        damage_ = 40;
        direction_ = {4,0};
        size_ = {0.4, 0.4};
    } else if (type == FORCEPODTWO && teams == Players) {
        damage_ = 60;
        direction_ = {4,0};
        size_ = {0.5, 0.5};
    }
    hit = false;
}

BulletType Bullet::getType() const {
    return type_;
}

void Bullet::setType(BulletType type) {
    type_ = type;
}

int Bullet::getUuid() const {
    return UUID_;
}

void Bullet::setUuid(int uuid) {
    UUID_ = uuid;
}

float Bullet::getDamage() const {
    return damage_;
}

void Bullet::setDamage(float damage) {
    damage_ = damage;
}

const std::string &Bullet::getFrom() const {
    return from_;
}

void Bullet::setFrom(const std::string &from) {
    from_ = from;
}

Teams Bullet::getTeam() const {
    return team_;
}

void Bullet::setTeam(Teams team) {
    team_ = team;
}

const Point<float> &Bullet::getPos() const {
    return pos_;
}

void Bullet::setPos(const Point<float> &pos) {
    pos_ = pos;
}

const Point<float> &Bullet::getDirection() const {
    return direction_;
}

void Bullet::setDirection(const Point<float> &direction) {
    direction_ = direction;
}

const Point<float> &Bullet::getSize() const {
    return size_;
}

void Bullet::setSize(const Point<float> &size) {
    size_ = size;
}

bool Bullet::isHit() const {
    return hit;
}

void Bullet::setHit(bool hit) {
    Bullet::hit = hit;
}
