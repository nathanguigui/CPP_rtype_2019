//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_BULLETRESPONSE_HPP
#define CPP_RTYPE_2019_BULLETRESPONSE_HPP


#include <client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp>

namespace RType {
    class BulletResponse : public IUdpResponse {
    public:
        enum BulletType {
            BULL_ONE,
            BULL_TWO,
            BULL_THREE,
            BULL_FOUR,
            BULL_FIVE,
            BULL_SIX,
            BULL_SEVEN
        };

        BulletResponse(std::string uuid, int posX, int posY, std::string type);

        std::string getUuid() const override;

        BulletType getBulletType() const;

        int getPosX() const override;

        int getPosY() const override;


        EntityType getType() override;

    private:
        std::string _uuid;
        BulletType _type;
        int _posX{};
        int _posY{};
        IUdpResponse::EntityType _entityType = IUdpResponse::EntityType::BULLET;

    };
}


#endif //CPP_RTYPE_2019_BULLETRESPONSE_HPP
