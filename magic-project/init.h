#ifndef INIT_H
#define INIT_H
#define GAME_PAIR 1
#include <stdbool.h>

typedef struct Player{
    int row;
    int col;
    int health;
    int agil;
    int str;
    int intel;
    int fire;
    int ice;
    char name[150];
}Player;

Player init_game(); //initialization player
void handlePlayerLevel(Player * player); //leveling of player
#endif
