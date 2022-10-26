#ifndef WEAPON_ITEM_H
#define WEAPON_ITEM_H

#include "../item_event.h"
#include "../../actions/action_combat.h"

class weapon_item : public item_event
{
	public:

	virtual bool fire(actor* target);


	protected:

	action_combat* fire_action;
};

#endif
