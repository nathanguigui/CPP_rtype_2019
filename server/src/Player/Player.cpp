//
// Created by glithaud on 11/23/19.
//

#include "Player.hpp"

Player::Player(std::string pseudo, std::string color): pseudo_(pseudo), color_(color) {
    std::cout << pseudo_ << " Created with color " << color_ << std::endl;
    life_ = 100.0;
    UUID_ = pseudo_ + color_;
    pos_ = {0, 0};
    size_ = {1,1};
    speed_ = {1, 0};
    playerState_ = ALIVE;
    shotSpeed_ = 0.5;
    rocketType_ = NORMAL;
}

Player::~Player() {

}

const std::string &Player::getPseudo() const {
    return pseudo_;
}

const std::string &Player::getColor() const {
    return color_;
}

const std::string &Player::getUuid() const {
    return UUID_;
}

const std::string &Player::getMove() const {
    return move_;
}

PlayerState Player::getPlayerState() const {
    return playerState_;
}

float Player::getLife() const {
    return life_;
}

float Player::getShotSpeed() const {
    return shotSpeed_;
}

const Point<float> &Player::getPos() const {
    return pos_;
}

const Point<float> &Player::getSize() const {
    return size_;
}

const Point<float> &Player::getSpeed() const {
    return speed_;
}

void Player::setPseudo(const std::string &pseudo) {
    pseudo_ = pseudo;
}

void Player::setColor(const std::string &color) {
    color_ = color;
}

void Player::setUuid(const std::string &uuid) {
    UUID_ = uuid;
}

void Player::setMove(const std::string &move) {
    move_ = move;
}

void Player::setPlayerState(PlayerState playerState) {
    playerState_ = playerState;
}

void Player::setLife(float life) {
    life_ = life;
}

void Player::setShotSpeed(float shotSpeed) {
    shotSpeed_ = shotSpeed;
}

void Player::setPos(const Point<float> &pos) {
    pos_ = pos;
}

void Player::setSize(const Point<float> &size) {
    size_ = size;
}

void Player::setSpeed(const Point<float> &speed) {
    speed_ = speed;
}
