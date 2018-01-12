//
// Created by nano on 1/10/18.
//

#ifndef CPP_RTYPE_ENTITYMANAGER_HPP
#define CPP_RTYPE_ENTITYMANAGER_HPP


#include <vector>
#include "AEntity.hpp"

class EntityManager {
public:
    EntityManager();
    ~EntityManager();
    void addEntity(AEntity *entity);
    const std::vector<AEntity*> &getEntity() const;
    void setEntity(const std::vector<AEntity*> &entity);
    AEntity *operator[] (int id);
    std::vector<AEntity *> operator[] (EntiType type);

private:
    std::vector<AEntity*> _entity;
};


#endif //CPP_RTYPE_ENTITYMANAGER_HPP
