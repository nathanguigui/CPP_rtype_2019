//
// Created by guigui on 12/1/19.
//

#ifndef CPP_RTYPE_2019_PLAYERRESPONSE_HPP
#define CPP_RTYPE_2019_PLAYERRESPONSE_HPP

#include <cstring>
#include <client/src/core/SceneManager/ISceneManager.hpp>
#include "client/src/core/UdpNetwork/UdpResponse/IUdpResponse.hpp"

namespace RType {
    class PlayerResponse : public IUdpResponse {
    public:
        PlayerResponse(int score, int life, int attackSpeed, int posX, int posY, std::string forcePodLevel,
                       ISceneManager::PlayerStatus playerStatus, std::string name, std::string uuid);

        PlayerResponse(int score, ISceneManager::PlayerStatus playerStatus, std::string name, std::string uuid);

        EntityType getType() override;

        std::string getUuid() const override;

        std::string getName() const;

        int getScore() const;

        int getLife() const;

        int getAttackSpeed() const;

        int getPosX() const override;

        int getPosY() const override;

        ISceneManager::ForcePodLevel getForcePodLevel() const;

        ISceneManager::PlayerStatus getPlayerStatus() const;


    private:
        std::string _uuid;
        std::string _name;
        int _score;
        int _life{};
        int _attackSpeed{};
        int _posX{};
        int _posY{};
        ISceneManager::ForcePodLevel _forcePodLevel;
        ISceneManager::PlayerStatus  _playerStatus;
        IUdpResponse::EntityType _type = IUdpResponse::EntityType::PLAYER;
    };
}


#endif //CPP_RTYPE_2019_PLAYERRESPONSE_HPP
