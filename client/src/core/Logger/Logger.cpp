//
// Created by luc4s.p on 11/15/19.
//

#include "Logger.h"

RType::Logger::Logger() {

}

RType::Logger::~Logger() {

}

void RType::Logger::PrintInFile(std::string content) {

    std::ofstream LogFile;
    LogFile.open("Log.txt", std::ios::app);
    auto *buffer = std::cout.rdbuf();
    time_t now = time(0);

    tm *gmtm = gmtime(&now);
    char *dt = asctime(gmtm);
    dt[std::strlen(dt) - 1] = ':';
    dt[std::strlen(dt)] = ' ';

    std::cout.rdbuf(LogFile.rdbuf());

    std::cout << dt << "[\"" << content << "\"]" << std::endl;

    std::cout.rdbuf(buffer);

    LogFile.close();
}