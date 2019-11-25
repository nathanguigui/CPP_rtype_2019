//
// Created by guigui on 11/25/19.
//

#include <iostream>
#include "Exception.hpp"

RType::Exception::Exception(const std::string &err, ExceptionType type) : std::runtime_error(err), message(err), exceptionType(type) {}

const char *RType::Exception::what() const noexcept {
    if (exceptionType == ExceptionType::STARTUP)
        Exception::printHelp();
    return message.c_str();
}

void RType::Exception::printHelp() {
    std::cout << "RTYPE:\r\n\t./rtype_client [SERVER_IP] [SERVER_PORT] [USERNAME]\r\n\r\n\t[SERVER_IP] => ex:\"196.168.1.17\"";
    std::cout << "\r\n\t[SERVER_PORT] => ex:\"8080\"\r\n\t[USERNAME] => only alpha-numeric chars\r\n";
}
