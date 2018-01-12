//
// Created by nano on 1/10/18.
//

#include <iostream>
#include <algorithm>
#include "../include/EntityManager.hpp"

EntityManager::EntityManager() {
    std::cerr << "New class entityManager created." << std::endl;
}

EntityManager::~EntityManager() {
    std::cerr << "Class entityManager deleted." << std::endl;
}

const std::vector<AEntity *> &EntityManager::getEntity() const {
    return _entity;
}

void EntityManager::setEntity(const std::vector<AEntity *> &entity) {
    EntityManager::_entity = entity;
}

AEntity *EntityManager::operator[](int id) {
    auto it = std::find_if(_entity.begin(), _entity.end(),
                           [id](AEntity *toto) { return toto->get_id() == id; });
    if (it != _entity.end())
        return *it;
    return nullptr;
}

void EntityManager::addEntity(AEntity *entity) {
    _entity.push_back(entity);
}

std::vector<AEntity *> EntityManager::operator[](EntiType type) {
    std::vector<AEntity *> tab;
    std::for_each(_entity.begin(), _entity.end(), [type, this, &tab](AEntity *elem){
        if (type == elem->get_type())
            tab.push_back(elem);
    });
    return tab;
}


