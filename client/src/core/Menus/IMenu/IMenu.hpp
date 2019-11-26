//
// Created by guigui on 11/26/19.
//

#ifndef CPP_RTYPE_2019_IMENU_HPP
#define CPP_RTYPE_2019_IMENU_HPP

#include <client/src/core/EventableObject/EventableObject.hpp>

namespace RType {
    using namespace RType;

    class IMenu : public EventableObject {
    public:

        virtual void draw() = 0;

        virtual void handleText(sf::Event &evt) = 0;

    private:
    };
}

#endif //CPP_RTYPE_2019_IMENU_HPP
