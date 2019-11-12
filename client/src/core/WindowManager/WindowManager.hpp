//
// Created by guigui on 11/12/19.
//

#ifndef CPP_RTYPE_2019_WINDOWMANAGER_HPP
#define CPP_RTYPE_2019_WINDOWMANAGER_HPP
#include <SFML/Graphics.hpp>
#include "client/src/core/core.hpp"
#include "client/src/core/Event/Event.hpp"

namespace RType {
    using namespace RType;
    class WindowManager {
    public:
        explicit WindowManager(const std::string &name);
        void init();
        int run();
        ~WindowManager();

    private:
        sf::Window *_app;
        const std::string &_name;
        Event *_eventManager;
    };
}


#endif //CPP_RTYPE_2019_WINDOWMANAGER_HPP
