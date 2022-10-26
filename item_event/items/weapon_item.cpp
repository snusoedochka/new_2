#include "weapon_item.h"

#include "../../enemy_event/enemy_event.h"
#include "../../actors/player.h"

bool weapon_item::fire(actor* target)
{
	if(!owner)
		return false;

	size_t* apref;
	if(dynamic_cast<player*>(owner))
		apref = &dynamic_cast<player*>(owner)->getAP();
	else if(dynamic_cast<enemy_event*>(owner))
		apref = &dynamic_cast<enemy_event*>(owner)->getAP();
	if(!fire_action->canExecute(*apref, owner, target, &target->getParentCell()))
		return false;

	fire_action->execute(*apref, owner, target, &target->getParentCell());
	return true;
}
