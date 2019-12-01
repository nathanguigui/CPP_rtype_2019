//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_POWERUPRESPONSE_HPP
#define CPP_RTYPE_2019_POWERUPRESPONSE_HPP

#include <client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp>

namespace RType {
    class PowerupResponse : public IUdpResponse {
    public:

        enum PowerupType {
            HEALTH_POW,
            ATTACK_POW
        };

        PowerupResponse(std::string uuid, int posX, int posY, std::string powType);

        const std::string &getUuid() const;

        PowerupType getType1() const;

        int getPosX() const;

        int getPosY() const;

        EntityType getType() override;

    private:
        std::string _uuid;
        PowerupType _type;
        int _posX{};
        int _posY{};
        IUdpResponse::EntityType _entityType = IUdpResponse::EntityType::POWERUP;
    };
}


#endif //CPP_RTYPE_2019_POWERUPRESPONSE_HPP
