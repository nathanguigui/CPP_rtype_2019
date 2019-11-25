//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_UTILS_HPP
#define CPP_RTYPE_2019_UTILS_HPP


template <typename T>
struct Point {
    T x;
    T y;
};

template <typename T>
bool operator==(Point<T> a, Point<T> b)
{
    return a.x == b.x && a.y == b.y;
}

enum GameState {
    CREATION,
    LAUNCHED,
    FINISHED,
    BETWEENGAME
};

enum Color {
    BLUE,
    RED,
    YELLOW,
    GREEN,
    UNDEFINED
};

enum PlayerState {
    ALIVE,
    DEAD
};

enum Teams {
    Players,
    Monsters
};

enum RocketType {
    NORMAL,
};

enum MonsterType {

};

#endif //CPP_RTYPE_2019_UTILS_HPP
