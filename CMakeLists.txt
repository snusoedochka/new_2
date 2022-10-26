cmake_minimum_required(VERSION 3.21)
project(oop_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp cell_object.cpp cell_object_view.cpp field_view.cpp field.cpp cells/cell_view.cpp cells/cell.cpp cells/cell_entrance.cpp cells/cell_exit.cpp actors/actor.cpp actors/player.cpp enemy_event/enemy_event.cpp enemy_event/enemies/acolyte.cpp enemy_event/enemies/skeleton.cpp actions/action_combat.cpp actions/action_shoot_ballistic.cpp actions/action_move.cpp actions/action.cpp item_event/item_event.cpp item_event/items/armor_item.cpp game_conditions/exit_condition.cpp game_conditions/player_death_condition.cpp logger/fstream_wrapper.cpp logger/logger.cpp logger/ostream_wrapper.cpp logger/observer/observable.cpp logger/observer/observer.cpp logger/observer/observer_actor.cpp)
