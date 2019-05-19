#ifndef STAGE_H
#define STAGE_H
#include "init.h"
#define MAPSIZE 10
void set_map(); //рисовка дуэльной комнаты
void stage(Player * player);//функци€ активирующа€ set_map, set_enemy() и game()
Player set_enemy(); //инициализа€ци€ оппонента
void game(Player * player, Player * enemy); // дуэльный цикл, включающий меню магии и ее вызов
void clearMenu(); //очистка меню заклинаний
void printPlayers(Player * player, Player * enemy); // меню отображающа€ имена и HP магов
#endif
