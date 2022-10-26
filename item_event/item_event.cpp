#include "item_event.h"

#include "../cell_object_view.h"
#include "../actors/player.h"
#include <typeinfo>


// events

void item_event::onWalkedIn(actor& by_who)
{
	player* p = dynamic_cast<player*>(&by_who);
	if(p){
		if(p->addItemToInventory(this)){
			if(hasParentCell()) getParentCell().set_object(nullptr);
		}
	}
}

// properties

void item_event::initView() { vw = new cell_object_view('+', *this); }

size_t item_event::getAmount() const { return amount; }
void item_event::setAmount(size_t amount)
{
	this->amount = amount;
	if(this->amount == 0) {
		if(hasParentCell()) getParentCell().set_object(nullptr);
	}
}

actor& item_event::getOwner() const { return *owner; }
void item_event::setOwner(actor* o) { owner = o; }

bool item_event::join(const item_event& other)
{
	if(typeid(other).hash_code() != typeid(*this).hash_code())
		return false;

	amount += other.getAmount();
	return true;
}

std::vector<action*>::iterator item_event::getActionsBegin(){ return actions.begin(); }
std::vector<action*>::iterator item_event::getActionsEnd(){ return actions.end(); }