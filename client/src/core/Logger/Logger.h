//
// Created by luc4s.p on 11/15/19.
//

#ifndef CPP_RTYPE_2019_LOGGER_H
#define CPP_RTYPE_2019_LOGGER_H

#include "client/src/core/CoreObject/CoreObject.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>

namespace RType {
    using namespace RType;
    class Logger : public CoreObject {
    public:
        Logger();
        ~Logger();

        void PrintInFile(std::string);
    private:

    };
}

#endif //CPP_RTYPE_2019_LOGGER_H
