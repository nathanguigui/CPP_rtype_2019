//
// Created by guigui on 11/25/19.
//

#ifndef CPP_RTYPE_2019_EXCEPTION_HPP
#define CPP_RTYPE_2019_EXCEPTION_HPP
#include <stdexcept>

namespace RType {

    using namespace RType;

    enum ExceptionType {
        STARTUP,
        NETWORK,
        GAME
    };

    class Exception : public std::runtime_error {
    public:
        /// Default ctor
        Exception(const std::string &err, ExceptionType type);

        /// Default dtor
        ~Exception() noexcept override = default;

        /// Override what
        const char *what() const noexcept override;

        /// Print Help
        static void printHelp();

    private:
        std::string message;
        ExceptionType exceptionType;
    };
}


#endif //CPP_RTYPE_2019_EXCEPTION_HPP
