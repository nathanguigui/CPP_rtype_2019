//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_MONSTERRESPONSE_HPP
#define CPP_RTYPE_2019_MONSTERRESPONSE_HPP


#include <client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp>

namespace RType {
    class MonsterResponse : public IUdpResponse {
    public:

        MonsterResponse(std::string uuid, int posX, int posY, std::string type);

        enum MonsterType {
            ALPHA,
            BETTA,
            GAMMA,
            DELTA
        };

        std::string getUuid() const override;

        MonsterType getMonsterType() const;

        int getPosX() const override;

        int getPosY() const override;

        EntityType getType() override;


    private:
        std::string _uuid;
        MonsterType  _type;
        int _posX{};
        int _posY{};
        IUdpResponse::EntityType _entityType = IUdpResponse::EntityType::MONSTER;

    };
}


#endif //CPP_RTYPE_2019_MONSTERRESPONSE_HPP
