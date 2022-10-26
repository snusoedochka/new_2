#include "enemy_event.h"

#include "../cell_object_view.h"

#include <iostream>

// Properties

void enemy_event::initView() { vw = new cell_object_view('&', *this); }

size_t& enemy_event::getAP() { return ap; }

// Events

void enemy_event::onAdd(cell& holder){}

void enemy_event::onTurn()
{
	ap = max_ap;

	std::vector<cell*> nc = getParentCell().get_neighbour_cells(detection_dist);
	actor* last_attack_target = nullptr;

	for(size_t i = 0; i < nc.size(); ++i)
	{
		cell* c = nc[i];
		if(!c->has_object())
			continue;
		actor* a = dynamic_cast<actor*>(&c->get_object());
		if(a == nullptr)
			continue;
		if(a->getTeamID() == getTeamID())
			continue;

		while(a != nullptr && a->getHealth() > 0
			&& atk_action->tryExecute(ap, this, a, c)){
			last_attack_target = a;
		}
	}

	if(last_attack_target == nullptr)
	{
		cell* target_cell = nullptr;
		actor* target = nullptr;
		size_t target_dist = (size_t)-1;

		for(size_t i = 0; i < nc.size(); ++i)
		{
			cell* c = nc[i];
			if(!c->has_object())
				continue;
			actor* a = dynamic_cast<actor*>(&c->get_object());
			if(a == nullptr)
				continue;
			if(a->getTeamID() == getTeamID())
				continue;

			if(a->getHealth() > 0 && c->get_distance(this->getParentCell()) < target_dist){
				target_cell = c;
				target = a;
				target_dist = c->get_distance(this->getParentCell());
			}
		}

        if(target)
            mv_action->tryExecute(ap, this, target, target_cell);
	}
}

void enemy_event::onDeath()
{
	getParentCell().set_object(nullptr);
	delete this;
}


void enemy_event::onWalkedIn(actor& by_who){}
void enemy_event::onWalkOn(cell& to_where){}
