#ifndef ACTION_H
#define ACTION_H

#include "../actors/actor.h"
#include <string>

class action
{
	public:

	virtual size_t getAPCost(actor* active, actor* passive, cell* c) = 0;
	virtual bool canExecute(size_t ap, actor* active, actor* passive, cell* c) = 0;

    virtual void execute(size_t& ap, actor* active, actor* passive, cell* c) = 0; //was string to disp
    virtual bool tryExecute(size_t& ap, actor* active, actor* passive, cell* c);
};

#endif
