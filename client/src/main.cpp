//
// Created by guigui on 11/12/19.
//

#include <iostream>
#include "client/src/core/WindowManager/WindowManager.hpp"

int main(int argc, char* argv[]) {

    auto game = new RType::WindowManager("test Window");

    game->processParams(argc, argv);
    int exitStatus = game->run();
    return exitStatus;
}