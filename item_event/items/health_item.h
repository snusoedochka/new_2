#ifndef HEALTH_ITEM_H
#define HEALTH_ITEM_H

#include "../item_event.h"

class health_item : public item_event
{
	public:

	health_item(size_t heal_amt);

	virtual void onUsed(actor& on_who);


	protected:

	size_t heal_amt;
};

#endif
