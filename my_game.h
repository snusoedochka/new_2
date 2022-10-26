#ifndef GAME_H
#define GAME_H

#include "enemy_event/enemies/acolyte.h"

#include "actors/actor_spawner.h"
#include "actors/actor_spawner.cpp"
#include "game_conditions/game_condition.h"

#include "actors/player.h"

#include "field.h"
#include "field_view.h"

#include "logger/ostream_wrapper.h"
#include "logger/observer/observer_actor.h"


class game
{
private:

    field* mainfield;
    field_view* mainfield_view;

    player* mainplr = nullptr;
    static std::vector<actor_spawner_func> enemy_spawn_funcs;
    std::vector<actor*> actors_spawned;

    game_condition& win_cond;
    game_condition& lose_cond;


public:

    // game management
    game(game_condition& win_cond, game_condition& lose_cond);
    ~game();

    void init();
    void run();

    // public getters
    const player* getMainPlayer();
};

#endif