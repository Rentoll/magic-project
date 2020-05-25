#ifndef STAGE_H
#define STAGE_H
#include "init.h"
#define MAPSIZE 10
void set_map(); //draw dueling room
void stage(Player * player);//activating set_map, set_enemy() and game()
Player set_enemy(); //enemy initialization
void game(Player * player, Player * enemy); // duel loop, including using magic
void clearMenu(); //clearing menu of magic
void printPlayers(Player * player, Player * enemy); // displaying names and HP of mages
#endif
