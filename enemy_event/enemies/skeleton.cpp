#include "skeleton.h"

skeleton::skeleton()
{
	initView();

	max_ap = 6;
	detection_dist = 20;

	setMaxHealth(80);
	setDamageThreshold(6);
	setDamageResistance(0.2);

	atk_action = new action_shoot_ballistic(1, 5, 3);
	mv_action = new action_move(2);
}
const char* skeleton::getName() const { return "$ke1eton"; }