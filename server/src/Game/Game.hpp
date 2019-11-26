//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_GAME_HPP
#define CPP_RTYPE_2019_GAME_HPP

#include "../Player/Player.hpp"
#include "../Map/Map.hpp"
#include "../Bullet/Bullet.hpp"
#include "../Utils/Utils.hpp"

class Game {
public:
    Game(std::vector<std::string> pseudo);
    ~Game();

    /// Lance la partie
    void Launch();
    /// Update la partie en cours
    void Update(std::vector<std::string> commands, float timeSinceUpdate);

    /// Positionne les players pour le début de la partie
    void setPlayer();
    /// Met à jour les prochains évenements de la partie
    void setActionInfo();
    /// Déplace la position du début de la partie visible
    void movePosX();
    /// Déplace un joueur s'il le peut
    void pMove(int i, std::string direction);
private:
    int currentMap_;
    std::string action_;
    std::string typeAction_;
    std::string typeActionMonster_;
    float actionY_;
    GameState gameState_;
    float posx_;
    float maxPosX_;
    float timeSinceUpdate_;
    int posAction_;



    std::vector<Player *> playerList_;
    std::vector<Map *> mapList_;
    std::vector<Bullet*> bulletList_;
};


#endif //CPP_RTYPE_2019_GAME_HPP