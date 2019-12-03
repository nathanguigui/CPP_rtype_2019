//
// Created by glithaud on 11/23/19.
//

#include "Map.hpp"
//Distance d'affichage 24 par 32
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
        actionList_.emplace_back("35;ADD;bédodo;10");
        actionList_.emplace_back("35;ADD;bédodo;15");
        actionList_.emplace_back("35;ADD;bédodo;20");
        actionList_.emplace_back("40;ADD;bédodo;10");
        actionList_.emplace_back("40;ADD;bédodo;15");
        actionList_.emplace_back("40;ADD;bédodo;20");
        actionList_.emplace_back("45;ADD;bédodo;10");
        actionList_.emplace_back("45;ADD;bédodo;15");
        actionList_.emplace_back("45;ADD;bédodo;20");
        actionList_.emplace_back("65;ADD;bédodo;10");
        actionList_.emplace_back("65;ADD;bédodo;15");
        actionList_.emplace_back("65;ADD;bédodo;20");
        actionList_.emplace_back("75;ADD;bédodo;15");
        actionList_.emplace_back("75;ADD;bédodo;20");
        actionList_.emplace_back("76;ADD;bédodo;15");
        actionList_.emplace_back("76;ADD;bédodo;10");
        actionList_.emplace_back("77;ADD;bédodo;10");
        actionList_.emplace_back("77;ADD;bédodo;15");
        actionList_.emplace_back("78;ADD;bédodo;10");
        actionList_.emplace_back("78;ADD;bédodo;15");
        actionList_.emplace_back("85;ADD;bédodo;20");
        actionList_.emplace_back("95;ADD;Boss1;20");
        actionList_.emplace_back("97;ADD;Boss1;15");
        actionList_.emplace_back("100;END");
    }
    if (level == 2) {
        size_ = 100;
        height_ = 24;
        speed_ = 1000;
        currentAction_ = 0;
        for (int i = 0; i < 100; i++) {
            collideBot_.push_back(0);
            collideTop_.push_back(0);
        }
        actionList_.emplace_back("35;ADD;Grey;10");
        actionList_.emplace_back("35;ADD;Grey;15");
        actionList_.emplace_back("35;ADD;Grey;20");
        actionList_.emplace_back("40;ADD;Grey;10");
        actionList_.emplace_back("40;ADD;Grey;15");
        actionList_.emplace_back("40;ADD;Grey;20");
        actionList_.emplace_back("45;ADD;Grey;10");
        actionList_.emplace_back("45;ADD;Grey;15");
        actionList_.emplace_back("45;ADD;Grey;20");
        actionList_.emplace_back("65;ADD;Grey;10");
        actionList_.emplace_back("65;ADD;Grey;15");
        actionList_.emplace_back("65;ADD;Grey;20");
        actionList_.emplace_back("95;ADD;Green;20");
        actionList_.emplace_back("97;ADD;Green;15");
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
