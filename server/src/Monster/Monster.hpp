//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_MONSTER_HPP
#define CPP_RTYPE_2019_MONSTER_HPP

#include "../Utils/Utils.hpp"

class Monster {
public:
    Monster(std::string type, int nbID, float x,float y);
    ~Monster();

    const std::string &getType() const;
    void setType(const std::string &type);
    const std::string &getUuid() const;
    void setUuid(const std::string &uuid);
    float getLife() const;
    void setLife(float life);
    const Point<float> &getPos() const;
    void setPos(const Point<float> &pos);
    const Point<float> &getDirection() const;
    void setDirection(const Point<float> &direction);
    float getSpeed() const;
    void setSpeed(float speed);
    float getShotSpeed() const;
    void setShotSpeed(float shotSpeed);
    float getTimeNextShoot() const;
    void setTimeNextShoot(float timeNextShoot);

private:
    std::string type_;
    std::string UUID_;
    float life_;
    Point<float> pos_;
    Point<float> direction_;
    float speed_;
    float shotSpeed_;
    float timeNextShoot_;
};


#endif //CPP_RTYPE_2019_MONSTER_HPP
