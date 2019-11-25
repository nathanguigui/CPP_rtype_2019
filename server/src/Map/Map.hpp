//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_MAP_HPP
#define CPP_RTYPE_2019_MAP_HPP

#include <vector>
#include <string>

class Map {
public:
    explicit Map(int level);
    ~Map();

    int getSize() const;
    int getHeight() const;
    int getSpeed() const;
    int getLevel() const;
    int getCollideTop(int x) const;
    int getCollideBot(int x) const;
    std::string getNextAction();

private:
    int size_;
    int height_;
    int speed_;
    int level_;
    int currentAction_;

    std::vector<int> collideTop_;
    std::vector<int> collideBot_;

    std::vector<std::string> actionList_;
};


#endif //CPP_RTYPE_2019_MAP_HPP
