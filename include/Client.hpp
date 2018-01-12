//
// Created by simon on 09/01/18.
//

#ifndef CPP_RTYPE_CLIENT_HPP
#define CPP_RTYPE_CLIENT_HPP

#include <iostream>

#include "AMediated.hpp"

//la classe qui recevra tout les messages et qui les transmettra au mediateur
class Client : public AMediated
{
private:
    //UDP socket;
    bool _ingame;
    int _id;

public:
    Client(IMediator *mediator, int id) : AMediated(mediator), _ingame(false), _id(id) {}
    ~Client() {};
    void send();
    void dump();
    void testdeco();

    //seteurs geteurs
public:
    //void toto() {this->setMediator(new Room(true));}
    bool getIngame() const
    {
        return _ingame;
    }

    void setIngame(const bool &ingame)
    {
        _ingame = ingame;
    }
};


#endif //CPP_RTYPE_CLIENT_HPP
