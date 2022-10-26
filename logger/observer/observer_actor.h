#ifndef OBSERVER_ACTOR_H
#define OBSERVER_ACTOR_H

#include "observer.h"
#include "../../actors/actor.h"

class observer_actor : public observer
{

public:

    using observer::observer;
    virtual void setActor(actor& ac);
    virtual void notify();

private:

    actor* ac;

};

#endif