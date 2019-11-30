//
// Created by guigui on 11/12/19.
//

#include <iostream>
#include "client/src/core/WindowManager/WindowManager.hpp"

int main(int argc, char* argv[]) {

    int exitStatus;
    try {
        auto game = new RType::WindowManager("test Window");
        game->processParams(argc, argv);
        exitStatus = game->run();
    } catch (RType::Exception &exception) {
        std::cout << exception.what();
        exitStatus = RTYPE_defaultError;
    }
    return exitStatus;
}