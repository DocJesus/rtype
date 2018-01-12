//
// Created by simon on 09/01/18.
//

#include "../include/Room.hpp"

//fonction test de deco !!
void Room::test()
{
    _players[0]->testdeco();
}

void Room::addPlayer(Client *client)
{
    _players.push_back(client);
    if (_players.size() == _limit)
        _isLock = true;
}

//methode qui va lancer une partie
//mettre une thread !!!!!
void Room::LaunchGame()
{
    //voir le behavior du game pour faire cette partie
}

void Room::mediate(AMediated *elem)
{
    std::cout << "Room mediate" << std::endl;
    if (!_gameLaunch)
    {
        if (elem->getData().action == START)
        {
            //lancer le thread du launchgame
            _gameLaunch = true;
        }
        if (elem->getData().action == DISCONNECT)
            removePlayer(elem->getData().senderId);
    }
    else
    {
        cmds command;

        command.first = elem->getData().action;
        command.second = elem->getData().senderId;
        //mutex.lock?
        _orders.push(command);
        //mutex.unlock ?
    }
}

//on retire un joueur et on met son _ingame a false
//la room devient ouverte a tous meme si au depart elle était sologame;
void Room::removePlayer(int id)
{
    int i = 0;

    while (i != _players.size() && _players[i]->getData().senderId != id)
        i = i + 1;
    _serv.clientDecoFromRoom(id);
    _players.erase(_players.begin() + i);
    if (_players.empty())
    {
        _isLock = false;
        _orders.empty();
    }
}

void Room::dump()
{
    std::cout << "je suis une room" << std::endl;
    std::cout << "Et je possède " << _players.size() << "joueurs chez moi" << std::endl;
    for (int i = 0; i < _players.size(); ++i)
        _players[i]->dump();
    std::cout << "je suis " << _isLock << " lock" << std::endl;
}

