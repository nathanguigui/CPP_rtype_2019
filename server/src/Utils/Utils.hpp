//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_UTILS_HPP
#define CPP_RTYPE_2019_UTILS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>

template <typename T>
struct Point {
    T x;
    T y;
};

struct MPattern
{
    std::vector<Point<float> *> move;
    std::vector<int> speed;
    std::vector<int> time;
};

enum PowerUpStyle {
    HEALTH,
    SHOTSPEED
};

struct PowerUp {
    std::string UUID;
    Point<float> pos;
    Point<float> size;
    PowerUpStyle style;
};

enum GameState {
    CREATION,
    LAUNCHED,
    BETWEENGAME,
    ENDGAME,
    FINISHED,
    WINGAME
};

enum ObjectState {
    ALIVE,
    DEAD
};

enum Teams {
    Players,
    Monsters
};

enum BulletType {
    NORMAL,
    FORCEPODONE,
    FORCEPODTWO,
    BOSSONE
};

std::string string_to_hex(const std::string& input);
std::string hex_to_string(const std::string& input);

#endif //CPP_RTYPE_2019_UTILS_HPP
