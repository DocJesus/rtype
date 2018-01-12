//
// Created by simon on 09/01/18.
//

#include "../include/Client.hpp"

//le bug : quand on créer une nouvelle room alors qu'il y en a deja,
//il nous chie dessus, mais avec une room c'est cool

void Client::send()
{

    //ceci est un test
    _data.action = MULTIGAME;
    _data.senderId = _id;
    _mediator->mediate(this);
}

void Client::dump()
{
    std::cout << "je suis un joueur, mon ID est " << _id << " et je suis " << _ingame << " en game" << std::endl;
}

void Client::testdeco()
{
    std::cout << "debut testdeco" << std::endl;
    _data.action = DISCONNECT;
    _data.senderId = _id;
    _mediator->mediate(this);
    std::cout << "fin testdeco" << std::endl;
}