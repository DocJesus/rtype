//
// Created by vautri_b on 09/01/18.
//

#ifndef CPP_RTYPE_IMEDIATOR_HPP
#define CPP_RTYPE_IMEDIATOR_HPP

#include "AMediated.hpp"

class AMediated;

// Mediator is present to allow classes to communicate with each others
// Mediator interface
class IMediator
{
public:
    virtual void mediate(AMediated *) = 0;

};


#endif //CPP_RTYPE_IMEDIATOR_HPP
