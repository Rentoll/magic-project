#ifndef INIT_H
#define INIT_H
#define BACKGROUND COLOR_WHITE
#define PLAYER 1
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

Player init_game(); //инициазация игрока
void handlePlayerLevel(Player * player); //левелинг игрока
#endif
