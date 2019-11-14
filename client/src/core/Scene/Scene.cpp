//
// Created by guigui on 11/13/19.
//

#include "Scene.hpp"

RType::Scene::Scene(sf::RenderWindow *app): _app(app) {

}

RType::Scene::~Scene() = default;

void RType::Scene::draw() {
    for (auto & _object : this->_objects)
        _object->draw();
}

void RType::Scene::addSceneObject(SceneObject *object) {
    this->_objects.push_back(object);
}
