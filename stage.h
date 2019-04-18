#ifndef STAGE_H
#define STAGE_H
#include "init.h"
#define MAPSIZE 10
#define ANIMATIONDELAY 500
#define FIREBALL 1
#define IGNITION 2
#define FROST   3
#define HEAL    4
void set_map();
void stage(Player * player);
void useMagic(int magicType, Player * player, Player * enemy);
Player set_enemy();
void game(Player * player, Player * enemy);
void clearMenu();
void sendMagic(int magicType, Player player, bool deflected);
void heal(Player * player);
void enemyTurn(Player * player, Player * enemy);
void printPlayers(Player * player, Player * enemy);
#endif
