#include "player.h"

#include "../cell_object_view.h"
#include "../cells/cell_exit.h"
#include "../field.h"

player::player()
{
	initView();
}

// Properties

void player::initView() { vw = new cell_object_view('@', *this); }

void player::setAP(size_t ap) { this->ap = ap; }
void player::setMaxAP(size_t max_ap) { this->max_ap = max_ap; }
size_t& player::getAP() { return ap; }

const char* player::getName() const { return "Player"; }

// Inventory

bool player::addItemToInventory(item_event* i)
{
	for(size_t j = 0; j < inventory.size(); ++j)
		if(inventory[j]->join(*i))
			return true;

	if(inventory.size() >= max_inventory_size)
		return false;

	inventory.push_back(i);
	return true;
}

std::vector<item_event*>::iterator player::getInventoryBegin() { return inventory.begin(); }
std::vector<item_event*>::iterator player::getInventoryEnd() { return inventory.end(); }

// Events

void player::onAdd(cell& holder) {}

void player::onTurn()
{
    ap = max_ap;

}
void player::onDeath() {}

void player::onWalkedIn(actor& by_who) {}
void player::onWalkOn(cell& to_where){}


//action& player::getMoveAction() { return *mv_action; }