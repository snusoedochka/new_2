#ifndef SKELETON_H
#define SKELETON_H

#include "../enemy_event.h"
#include "../../actions/action_shoot_ballistic.h"

class skeleton : public enemy_event
{
	public:

	skeleton();

    const char* getName() const;
};

#endif
