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
    const MPattern &getTravel() const;
    void setTravel(const MPattern &travel);
    float getTimeLastTravelChanged() const;
    void setTimeLastTravelChanged(float timeLastTravelChanged);
    int getCurrentTravel() const;
    void setCurrentTravel(int currentTravel);
    const Point<float> &getSize() const;
    void setSize(const Point<float> &size);
    BulletType getBulletType() const;
    void setBulletType(BulletType bulletType);
    ObjectState getMonsterState() const;
    void setMonsterState(ObjectState monsterState);
    int getScore() const;
    void setScore(int score);
    PowerUpStyle getPowerUpStyle() const;
    int getPuProba() const;
    std::string getTypeHexa();

private:
    std::string type_;
    std::string UUID_;
    float life_;
    ObjectState monsterState_;
    Point<float> pos_;
    Point<float> size_;
    Point<float> direction_; // ?????
    MPattern travel_;
    BulletType bulletType_;
    PowerUpStyle powerUpStyle_;
    int puProba;
    float speed_;
    float shotSpeed_;
    float timeNextShoot_; // temps avant que le monstre ne commence à tirer quand il apparait
    float timeLastTravelChanged_; // Diminuer à tout les tours, il est égal à travel.time jusqu'a ce qu'il soit a 0
    int currentTravel_;
    int score_;
};


#endif //CPP_RTYPE_2019_MONSTER_HPP
