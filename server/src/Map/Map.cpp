//
// Created by glithaud on 11/23/19.
//

#include "Map.hpp"
//Distance d'affichage
Map::Map(int level): level_(level) {
    if (level == 1) {
        size_ = 100;
        height_ = 24;
        speed_ = 1000;
        currentAction_ = 0;
        for (int i = 0; i < 100; i++) {
            collideBot_.push_back(0);
            collideTop_.push_back(0);
        }
        actionList_.emplace_back("35;ADD;bédodo;3");
        actionList_.emplace_back("35;ADD;bédodo;1");
        actionList_.emplace_back("50;ADD;bédodo;2");
        actionList_.emplace_back("65;ADD;bédodo;4");
        actionList_.emplace_back("80;ADD;bédodo;6");
        actionList_.emplace_back("90;ADD;bédodo;1");
        actionList_.emplace_back("100;END");
    }
}

Map::~Map() {
    collideTop_.clear();
    collideBot_.clear();
    actionList_.clear();
}

int Map::getSize() const {
    return size_;
}

float Map::getSpeed() const {
    return speed_;
}

int Map::getLevel() const {
    return level_;
}

std::string Map::getNextAction() {
    currentAction_ = currentAction_ + 1;
    return actionList_[currentAction_ - 1];
}

int Map::getCollideTop(int x) const {
    return collideTop_[x];
}

int Map::getCollideBot(int x) const {
    return collideBot_[x];
}

int Map::getHeight() const {
    return height_;
}