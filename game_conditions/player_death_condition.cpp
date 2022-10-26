#include "player_death_condition.h"

bool player_death_condition::isMet()
{
    return plr && plr->getHealth() <= 0;
}

void player_death_condition::setPlayer(const player* plr) { this->plr = plr; }

//вернуть вариацию поля. разделит события,  игрок ходит