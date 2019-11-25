//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP

#include <vector>
#include <string>
#include <iostream>
#include "../Utils/Utils.hpp"

class Player {
public:
    explicit Player(std::string pseudo, std::string color);
    ~Player();

    const std::string &getPseudo() const;
    const std::string &getColor() const;
    const std::string &getUuid() const;
    const std::string &getMove() const;
    PlayerState getPlayerState() const;
    float getLife() const;
    float getShotSpeed() const;
    const Point<float> &getPos() const;
    const Point<float> &getSize() const;
    const Point<float> &getSpeed() const;
    void setPseudo(const std::string &pseudo);
    void setColor(const std::string &color);
    void setUuid(const std::string &uuid);
    void setMove(const std::string &move);
    void setPlayerState(PlayerState playerState);
    void setLife(float life);
    void setShotSpeed(float shotSpeed);
    void setPos(const Point<float> &pos);
    void setSize(const Point<float> &size);
    void setSpeed(const Point<float> &speed);

private:
    std::string pseudo_;
    std::string color_;
    std::string UUID_;
    std::string move_; //variable à changer pour bouger
    PlayerState playerState_;
    float life_;
    float shotSpeed_;
    Point<float> pos_;
    Point<float> size_;
    Point<float> speed_;
    RocketType rocketType_;
};


#endif //CPP_RTYPE_2019_PLAYER_HPP
