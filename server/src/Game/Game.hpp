//
// Created by glithaud on 11/23/19.
//

#ifndef CPP_RTYPE_2019_GAME_HPP
#define CPP_RTYPE_2019_GAME_HPP

#include "../Bullet/Bullet.hpp"
#include "../Map/Map.hpp"
#include "../Monster/Monster.hpp"
#include "../Player/Player.hpp"
#include "../Utils/Utils.hpp"

class Game {
public:
    Game(std::vector<std::string> pseudo);
    ~Game();

    /// Lance la partie
    void Launch();
    /// Update la partie en cours
    std::vector<std::string> Update(std::vector<std::string> commands, float timeSinceUpdate);

    /// Update l'état du jeu
    bool manageGameState();
    /// Reset la partie pour le prochain niveau
    void resetGame();
    /// Positionne les players pour le début de la partie
    void setPlayer();
    /// Met à jour les prochains évenements de la partie
    void setActionInfo();
    /// Déplace la position du début de la partie visible
    void movePosX();
    /// Déplace un joueur s'il le peut
    void pMove(int i, std::string direction);
    /// Shoot player
    void pShoot(int i);
    /// Force the player to stay on screen
    void pForceMove();
    /// Find the it of the player
    int findMe(std::string UUID);
    /// Execute Action
    void makeAction();
    /// Déplace le monstre
    void mMove(int i);
    /// Shoot Monsters
    void mShoot(int i);
    /// Détruit les monstres en dehors de la carte
    int mDestroyer(int i);
    /// Détruit les monstres morts
    void mDead();
    /// Update Shot timers
    void updateShotTimer();
    /// Mise à jour
    void bUpdate();
    /// Détruit les monstres
    void bDestroyer();
    /// Détruit les powerups en dehors de l'écran
    void puDestroyer();
    /// Write data for the client
    void writeData();

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
    int mUUID;
    int bID_;
    int puID;
    float timeToWait_;
    std::vector<std::string> data;

    std::vector<Player *> playerList_;
    std::vector<Monster *> monsterList;
    std::vector<Map *> mapList_;
    std::vector<Bullet*> bulletList_;
    std::vector<PowerUp> powerUpList_;
};


#endif //CPP_RTYPE_2019_GAME_HPP