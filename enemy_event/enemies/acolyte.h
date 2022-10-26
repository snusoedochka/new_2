#ifndef ACOLYTE_H
#define ACOLYTE_H

#include "../enemy_event.h"
#include "../../actions/action_shoot_ballistic.h"

class acolyte : public enemy_event
{
	public:

	acolyte();

    const char* getName() const;
};

#endif
