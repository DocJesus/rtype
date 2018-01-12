//
// Created by vautri_b on 10/01/18.
//

#ifndef CPP_RTYPE_IGAME_HPP
#define CPP_RTYPE_IGAME_HPP

#include <queue>
#include "AMediated.hpp"
//#include "EntityManager.hpp" //TODO uncomment

using cmds = std::pair<Action, int>;

class IGame
{
public:
    virtual ~IGame() = 0;
    virtual void start() = 0;
    virtual bool end() const = 0;
    virtual void updateBehavior() = 0; //comportements normaux (deplacement des non-joueur + spawn + missiles etc)
    virtual void updateAction(std::queue<cmds> &) = 0; //execute les input
    virtual void updateColision() = 0; //check colision
    virtual void updateEntities() = 0; // update l'etat des entites (alive, dead etc)
    //virtual const EntityManager& getEntities() const = 0; //TODO uncomment
    virtual void destroy() = 0; //detruit toute les entités, appel en fin de partie, en vrai on le met dans le destructeur
    virtual void setMapSize(int width, int length) = 0;
};

#endif //CPP_RTYPE_IGAME_HPP
