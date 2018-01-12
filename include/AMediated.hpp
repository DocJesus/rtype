//
// Created by vautri_b on 09/01/18.
//

#ifndef CPP_RTYPE_AMEDIATED_HPP
#define CPP_RTYPE_AMEDIATED_HPP

#include "IMediator.hpp"

class IMediator;

enum ModuleType
{
    UNDEFINED,
    DISPLAYER,
    NETWORK,
    INPUTRECIEVER,
    CLIENT,
    SERVER
};

enum Action
{
    NONE,
    CONNECT,
    DISCONNECT,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SHOOT,
    START,
    SOLOGAME,
    MULTIGAME,
};

struct  Data
{
    int senderId;
    Action action;

    Data(): senderId(0), action(NONE) {}
};

class   AMediated
{
protected:
    Data        _data;
    ModuleType  _type;
    IMediator   *_mediator;

public:
    AMediated (IMediator *mediator): _data(), _type(UNDEFINED), _mediator(mediator) {}
    virtual ~AMediated() {}
    virtual Data        getData() { return _data; }
    virtual ModuleType  getType() { return _type; }
    virtual void        setMediator(IMediator *mediator) {_mediator = mediator;}
    //virtual void doAction(AMediated *sender, Data data) = 0;

};

#endif //CPP_RTYPE_AMEDIATED_HPP
