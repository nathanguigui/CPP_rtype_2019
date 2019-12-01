//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_BULLET_HPP
#define CPP_RTYPE_2019_BULLET_HPP

#include "../Utils/Utils.hpp"

class Bullet {
public:
    Bullet(BulletType type, int UUID, std::string from, Teams teams, Point<float> pos);
    ~Bullet();

    BulletType getType() const;
    void setType(BulletType type);
    int getUuid() const;
    void setUuid(int uuid);
    float getDamage() const;
    void setDamage(float damage);
    const std::string &getFrom() const;
    void setFrom(const std::string &from);
    Teams getTeam() const;
    void setTeam(Teams team);
    const Point<float> &getPos() const;
    void setPos(const Point<float> &pos);
    const Point<float> &getDirection() const;
    void setDirection(const Point<float> &direction);
    const Point<float> &getSize() const;
    void setSize(const Point<float> &size);
    bool isHit() const;
    void setHit(bool hit);
    std::string getTypeHexa();

private:
    BulletType type_;
    int UUID_;
    bool hit;
    float damage_;
    std::string from_;
    Teams team_;
    Point<float> pos_;
    Point<float> direction_;
    Point<float> size_;
};


#endif //CPP_RTYPE_2019_BULLET_HPP
