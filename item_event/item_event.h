#ifndef ITEM_H
#define ITEM_H

#include "../actors/actor.h"
#include "../actions/action.h"
#include <vector>


class item_event : public actor
{
	public:

	// events
	void onWalkedIn(actor& by_who);
    //virtual void onUsed(actor& p) = 0;

	// properties

	size_t getAmount() const;
	void setAmount(size_t amount);

	actor& getOwner() const;
	void setOwner(actor* o);

	bool join(const item_event& other);

    std::vector<action*>::iterator getActionsBegin();
    std::vector<action*>::iterator getActionsEnd();


protected:

	void initView();

	actor* owner;
	size_t amount= 1;

    std::vector<action*> actions;
};

#endif
