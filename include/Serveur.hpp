//
// Created by simon on 09/01/18.
//

#ifndef CPP_RTYPE_SERVEUR_HPP
#define CPP_RTYPE_SERVEUR_HPP

#include <map>
#include <vector>
#include <queue>

#include "Room.hpp"
#include "Client.hpp"
#include "IMediator.hpp"

class Room;

//le serveur, celui qui à les room, les joueurs en attentes etc..
class Serveur : public IMediator
{
private:
    std::vector<Room> saloon;
    std::vector<Client> waitingQueue;
    //std::unordered_map<int,int> checkbook;
    //UDP socket;

public:
    Serveur() {}
    ~Serveur()
    {
        saloon.empty();
        waitingQueue.empty();
    }

    void test();

    void clientDecoFromRoom(int);
    int findClientById(int);
    void addClient(int);
    void addRoom(int, bool);
    void soloGame(int);
    void multiGame(int);
    void removeFromWaiting(int);
    virtual void mediate(AMediated *);
    void dump();

};


#endif //CPP_RTYPE_SERVEUR_HPP
