//
// Created by simon on 09/01/18.
//

#ifndef CPP_RTYPE_ROOM_HPP
#define CPP_RTYPE_ROOM_HPP

#include <queue>
#include <vector>
#include <ctime> //pour la clock

#include "Serveur.hpp"
#include "IMediator.hpp"
#include "Client.hpp"
#include "IGame.hpp"

class Serveur;

//les room de jeux
class Room : public IMediator
{
private:
    //les joueurs présents dans la room
    std::vector<Client*> _players;
    //le liste des ordres des joueurs
    std::queue<cmds> _orders;
    //le jeu //IGAME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //IGame _game;
    //si il peut acceuillir d'autres joueurs
    bool _isLock;
    //si la game est launch
    bool _gameLaunch;
    int _limit;
    Serveur &_serv;

//methodes
public:
    Room(bool isLock, Serveur &serv) : _isLock(isLock), _gameLaunch(false), _serv(serv)
    {
        /*_limit = _game.getLimit(); */
        std::cout << "création d'une room" << std::endl;
    }
    ~Room() {}

    void LaunchGame();
    void addPlayer(Client *client);
    virtual void mediate(AMediated *);
    //fct qui va retirer un joueur du vector et qui va voir si c'est le dernier etc...
    void removePlayer(int id);
    void dump();

    void test();

//seteurs geteurs
public:

    std::vector<Client*> &getPlayers()
    {
        return _players;
    }

    bool IsLock() const
    {
        return _isLock;
    }

    void SetLock(const bool &islock)
    {
        _isLock = islock;
    }

    void setLimit(int limit)
    {
        _limit = limit;
    }
};


#endif //CPP_RTYPE_ROOM_HPP
