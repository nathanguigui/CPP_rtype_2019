//
// Created by guigui on 11/13/19.
//

#include "MainMenu.hpp"

RType::MainMenu::MainMenu(sf::RenderWindow *app): _app(app) {

}

RType::MainMenu::~MainMenu() {

}

void RType::MainMenu::handleLeft() {
    std::cout << "click left";
}

void RType::MainMenu::handleRight() {
    std::cout << "click right";

}

void RType::MainMenu::handleUp() {
    std::cout << "click up";

}

void RType::MainMenu::handleDown() {
    std::cout << "click down";

}

void RType::MainMenu::handleEnter() {

}
