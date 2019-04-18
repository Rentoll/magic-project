#ifndef INIT_H
#define INIT_H
#define BACKGROUND COLOR_WHITE
#define PLAYER 1
#include <stdbool.h>

typedef struct Player{
    int row;
    int col;
    int health;
    int fire;
    int ice;
    int agil;
    int str;
    int intel;
    char name[150];
}Player;

Player init_game();
void handleLevel(Player * player);
#endif
