//
// Created by guigui on 11/13/19.
//

#ifndef CPP_RTYPE_2019_EVENTABLEOBJECT_HPP
#define CPP_RTYPE_2019_EVENTABLEOBJECT_HPP


namespace RType {
    class EventableObject {
    public:
        virtual void handleUp() = 0;
        virtual void handleDown() = 0;
        virtual void handleLeft() = 0;
        virtual void handleRight() = 0;
        virtual void handleEnter() = 0;
        virtual void handleKeyReleased() = 0;

    private:
    };
}


#endif //CPP_RTYPE_2019_EVENTABLEOBJECT_HPP
