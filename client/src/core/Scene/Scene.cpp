//
// Created by guigui on 11/13/19.
//

#include <client/src/core/WindowManager/IWindowManager.hpp>
#include <client/src/game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h>
#include <client/src/game/UdpResponse/BulletResponse/BulletResponse.hpp>
#include <client/src/game/Bullets/BulletsShoot/SuperBullet1/SuperBullet1.h>
#include <client/src/core/Gui/Tools.hpp>
#include <sstream>
#include <client/src/game/UdpResponse/MonsterResponse/MonsterResponse.hpp>
#include <client/src/game/enemies/GreenBoss/GreenBoss.h>
#include <client/src/game/enemies/LittleBrown/LittleBrown.h>
#include <client/src/game/enemies/LittleRed/LittleRed.h>
#include <client/src/game/enemies/OrangeBoss/OrangeBoss.h>
#include <client/src/game/Bullets/BulletsShoot/SuperBullet2/SuperBullet2.h>
#include <client/src/game/Bullets/BulletsShoot/SuperBullet3/SuperBullet3.h>
#include <client/src/game/Bullets/BulletsShoot/MasterBullet/MasterBullet.h>
#include <client/src/game/PowerUpSprite/Boost/Boost.h>
#include <client/src/game/UdpResponse/PowerupResponse/PowerupResponse.hpp>
#include <client/src/game/PowerUpSprite/Heal/Heal.h>
#include "Scene.hpp"

RType::Scene::Scene(sf::RenderWindow *app, IWindowManager *parent): _app(app), _parent(parent) {
    this->_background = new sf::Sprite();
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile("assets/MainMenu/logo.png");
    this->_background->setTexture(*this->_texture);
    this->_background->setPosition(0.0, 1.0);
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/fonts/ka.ttf");
    this->_backgroundTexture = new sf::Texture();
    this->_backgroundTexture->loadFromFile("assets/BydoEmpire/the_best.jpg");
    this->_backgroundSprite = new sf::Sprite();
    this->_backgroundSprite->setTexture(*this->_backgroundTexture);
    this->_backgroundSprite->scale(5, 5);
    this->_playerLife = new sf::Text("LIFE: LOADING...", *this->_font);
    this->_playerScore = new sf::Text("SCORE: LOADING...", *this->_font);
    auto screenSize = this->_app->getSize();
    _playerLife->setPosition(colPos(screenSize, _playerLife->getGlobalBounds().width, _playerLife->getPosition(), 5, 2));
    _playerScore->setPosition(colPos(screenSize, _playerScore->getGlobalBounds().width, _playerScore->getPosition(), 5, 4));
    _playerScore->setFillColor(sf::Color(sf::Color::White));
    _playerLife->setFillColor(sf::Color(sf::Color::White));
}

RType::Scene::~Scene() = default;

void RType::Scene::draw() {
    _app->draw(*_backgroundSprite);
    for (auto & _object : this->_sceneObjects)
        _object.second->draw();
    _app->draw(*_playerLife);
    _app->draw(*_playerScore);
}

void RType::Scene::addSceneObject(SceneObject *object) {
    std::string tmp = "toto";
    this->_sceneObjects.insert({tmp, object});
}

void RType::Scene::handleLeft() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleLeft();
}

void RType::Scene::handleRight() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleRight();
}

void RType::Scene::handleUp() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleUp();
}

void RType::Scene::handleDown() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleDown();
}

void RType::Scene::handleEnter() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleEnter();
}

void RType::Scene::handleKeyReleased() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->handleKeyReleased();
}

void RType::Scene::addEventableSceneObject(RType::EventableSceneObject *eventableSceneObject) {
    this->_eventableObjects.push_back(eventableSceneObject);
}

void RType::Scene::destroy() {
    for (auto & _eventableObject : this->_eventableObjects) _eventableObject->destroy();
    for (auto & _object : this->_sceneObjects) _object.second->destroy();
}

void RType::Scene::addPlayer(RType::Player::SkinColours skinColours) {
    if (this->_player)
        return;
    this->_player = new Player(this->_app, this, skinColours);
    this->_player->setUdpNetwork((UdpNetwork*)this->_parent->getUdpNetwork());
    this->addEventableSceneObject((EventableSceneObject*)this->_player);
    this->addSceneObject((SceneObject*)this->_player);
}

void RType::Scene::updateObject(const std::string& uuid, RType::SceneObject *object) {
    if (this->_sceneObjects.find(uuid) == this->_sceneObjects.end()) {
        this->_sceneObjects.insert({uuid, object});
    }
}

void RType::Scene::updateCurrentPlayer(const std::string& uuid, const std::string& name, RType::ISceneManager::PlayerStatus status,
                                       int score, int life, int attackSpeed, int posX, int posY,
                                       RType::ISceneManager::ForcePodLevel forcePodLevel) {
    this->_player->setPosition(sf::Vector2f(posX/4, posY/4));
    std::stringstream ss;
    ss << "SCORE: " << score;
    _playerScore->setString(ss.str());
    ss.str("");
    ss << "LIFE: " << life;
    _playerLife->setString(ss.str());
}

void RType::Scene::updateCurrentPlayer(const std::string& uuid, const std::string& name, RType::ISceneManager::PlayerStatus status,
                                       int score) {

}

void RType::Scene::updateEntity(RType::IUdpResponse *udpResponse) {
    /// Entity exist
    if (this->_sceneObjects.find(udpResponse->getUuid()) != this->_sceneObjects.end())
        this->_sceneObjects[udpResponse->getUuid()]->setPosition(sf::Vector2f(udpResponse->getPosX() / 4,udpResponse->getPosY() / 4));
    else { /// Entity doesn't exist
        std::cout << "creating entity\r\n";
        SimpleBullet *pSimpleBullet = nullptr;
        SuperBullet1 *superBullet1 = nullptr;
        SuperBullet2 *superBullet2 = nullptr;
        SuperBullet3 *superBullet3 = nullptr;
        MasterBullet *masterBullet = nullptr;
        Boost *boost1 = nullptr;
        Heal *heal = nullptr;
        GreenBoss *greenBoss = nullptr;
        LittleBrown *littleBrown = nullptr;
        LittleRed *littleRed = nullptr;
        OrangeBoss *orangeBoss = nullptr;

        switch (udpResponse->getType()) {
            case IUdpResponse::PLAYER:
                break;
            case IUdpResponse::MONSTER:
                switch (((MonsterResponse*)udpResponse)->getMonsterType()) {
                    case MonsterResponse::ALPHA:
                        littleRed = new LittleRed(this->_app);
                        littleRed->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), littleRed});
                        break;
                    case MonsterResponse::BETTA:
                        littleBrown = new LittleBrown(this->_app);
                        littleBrown->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), littleBrown});
                        break;
                    case MonsterResponse::GAMMA:
                        orangeBoss = new OrangeBoss(this->_app);
                        orangeBoss->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), orangeBoss});
                        break;
                    case MonsterResponse::DELTA:
                        greenBoss = new GreenBoss(this->_app);
                        greenBoss->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), greenBoss});
                        break;
                }
                break;
            case IUdpResponse::BULLET:
                switch (((BulletResponse*)udpResponse)->getBulletType()) {
                    case BulletResponse::BULL_ONE:
                        pSimpleBullet = new SimpleBullet(this->_app);
                        pSimpleBullet->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), pSimpleBullet});
                        break;
                    case BulletResponse::BULL_TWO:
                        pSimpleBullet = new SimpleBullet(this->_app);
                        pSimpleBullet->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), pSimpleBullet});
                        break;
                    case BulletResponse::BULL_THREE:
                        superBullet1 = new SuperBullet1(this->_app);
                        superBullet1->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), superBullet1});
                        break;
                    case BulletResponse::BULL_FOUR:
                        superBullet2 = new SuperBullet2(this->_app);
                        superBullet2->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), superBullet2});
                        break;
                    case BulletResponse::BULL_FIVE:
                        superBullet3 = new SuperBullet3(this->_app);
                        superBullet3->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), superBullet3});
                        break;
                    case BulletResponse::BULL_SIX:
                        superBullet2 = new SuperBullet2(this->_app);
                        superBullet2->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), superBullet2});
                        break;
                    case BulletResponse::BULL_SEVEN:
                        masterBullet = new MasterBullet(this->_app);
                        masterBullet->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), masterBullet});
                        break;
                }
                break;
            case IUdpResponse::POWERUP:
                switch (((PowerupResponse *)udpResponse)->getType1()) {
                    case PowerupResponse::HEALTH_POW:
                        heal = new Heal(this->_app);
                        heal->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), heal});
                        break;
                    case PowerupResponse::ATTACK_POW:
                        boost1 = new Boost(this->_app);
                        boost1->setPosition({static_cast<float>(udpResponse->getPosX() / 4), static_cast<float>(udpResponse->getPosY() / 4)});
                        this->_sceneObjects.insert({udpResponse->getUuid(), boost1});
                        break;
                }
                break;
        }
    }
}

void RType::Scene::updateBackgroundPos(int posX) {
    float off = posX / 400;
    this->_backgroundSprite->move(-off, 0);
}
