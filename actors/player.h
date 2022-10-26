#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "../item_event/item_event.h"
#include "../actions/action_move.h"


class player : public actor
{
	public:

	player();

	// Properites
    void setAP(size_t ap);
    void setMaxAP(size_t max_ap);
	size_t& getAP();

    virtual const char* getName() const;

	// Inventory
	bool addItemToInventory(item_event* i);
    std::vector<item_event*>::iterator getInventoryBegin();
    std::vector<item_event*>::iterator getInventoryEnd();

	// Events
	virtual void onAdd(cell& holder);

	virtual void onTurn();
	virtual void onDeath();

	virtual void onWalkedIn(actor& by_who);
	virtual void onWalkOn(cell& to_where);

    //action& getMoveAction();
	protected:

	virtual void initView();

	size_t ap, max_ap;

	std::vector<item_event*> inventory;
	size_t max_inventory_size = 10;


	action_move* mv_action;
};

#endif
