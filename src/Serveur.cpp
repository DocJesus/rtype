//
// Created by simon on 09/01/18.
//

#include "../include/Serveur.hpp"

void Serveur::test()
{
    char n;

    addClient(0);
    addClient(1);
    addClient(2);
    /*addClient(3);*/
    dump();
    std::cin >> n;
    waitingQueue[0].send();
    waitingQueue[1].send();
    waitingQueue[2].send();
    /*waitingQueue[0].send();*/
    dump();
    saloon[0].test();
    //saloon[1].test();
    //saloon[2].test();
    /*saloon[3].test();*/
    std::cin >> n;
    dump();

}

//quand un joueur se deco d'une room,
//la room appelle cette méthode pour dire que le joueur n'est plus en jeu
void Serveur::clientDecoFromRoom(int id)
{
    int i = findClientById(id);

    waitingQueue[i].setIngame(false);
}

int Serveur::findClientById(int id)
{
    int i = 0;

    while (i != waitingQueue.size() && waitingQueue[i].getData().senderId != id)
        i = i + 1;
    return i;
}

void Serveur::addClient(int i)
{
    Client client(this, i);

    waitingQueue.push_back(client);
}

void Serveur::addRoom(int playerId, bool tmp)
{
    int i = findClientById(playerId);
    Room newRoom(tmp, *this);
    saloon.push_back(newRoom);
    waitingQueue[i].setMediator(&saloon[saloon.size() - 1]);
    waitingQueue[i].setIngame(true);
    saloon[saloon.size() - 1].addPlayer(&waitingQueue[i]);
}

void Serveur::soloGame(int playerId)
{
    addRoom(playerId, true);
}

void Serveur::multiGame(int playerId)
{
    int i = 0;
    bool tmp = true;

    //check si une des room est dispo pour avoir d'autre joueurs
    //saloon.Islock() == true -> ne peut pas recevoir d'autres joueurs
    //saloon.Islokc() == false -> peut recevoir d'autres joueurs
    while (i != saloon.size() && tmp)
    {
        tmp = saloon[i].IsLock();
        i = i + 1;
    }
    //i - 1 parceque sinon il va une case trop loins dans saloon
    i = i - 1;
    //il n'y aucune room de dispo alors on en créer une
    if (tmp)
        addRoom(playerId, false);
    else
    {
        //sinon il met le joueur dans la room qu'il a trouvé
        int j = findClientById(playerId);
        waitingQueue[j].setMediator(&saloon[i]);
        waitingQueue[j].setIngame(true);
        saloon[i].addPlayer(&waitingQueue[j]);
    }
}

//supprime un joueur de la queue
void Serveur::removeFromWaiting(int playerId)
{
    waitingQueue.erase(waitingQueue.begin() + findClientById(playerId));
}

void Serveur::mediate(AMediated *elem)
{
    Action todo;

    std::cout << "serveur mediate" << std::endl;

    todo = elem->getData().action;
    switch (todo)
    {
        case SOLOGAME:
            soloGame(elem->getData().senderId);
            break;
        case MULTIGAME:
            multiGame(elem->getData().senderId);
            break;
        case DISCONNECT:
            removeFromWaiting(elem->getData().senderId);
            break;
        default:
            break;
    }
}


void Serveur::dump()
{
    int i = 0;

    std::cout << "saloon dump" << std::endl;
    std::cout << "je possède " << saloon.size() << " salons" << std::endl;
    while (i != saloon.size())
       saloon[i++].dump();
    i = 0;
    std::cout << "waitingqueue dump" << std::endl;
    while (i != waitingQueue.size())
       waitingQueue[i++].dump();
}
