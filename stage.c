#include <panel.h>
#include <string.h>
#include "nameGenerator.h"
#include "stage.h"
#include "nextLevel.h"
#include "magic.h"

void set_map(){
    int row;
    int col;
    int map[MAPSIZE][MAPSIZE] =    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    getmaxyx(stdscr, row, col);
    init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    for(int i = 0; i < MAPSIZE; i++) {
        for(int j = 0; j < MAPSIZE; j++) {
            switch(map[i][j]) {
                case 0:
                    mvaddch(i+5, j+10, '#');
                    break;
                case 1:
                    mvaddch(i+5, j+10, '.');
                    break;
                default:
                    mvaddch(i+5, j+10, ' ');
                    break;
            }
        }
    }
    attroff(1);
}

void clearMenu(){
    move(20, 0);
    clrtoeol();
    move(21, 0);
    clrtoeol();
}

void printPlayers(Player * player, Player * enemy){

    move(1, 0);
    clrtoeol();
    move(2, 0);
    clrtoeol();
    mvprintw(1, 1, player->name);
    mvprintw(1, 20, "Health - %i", player->health);
    mvprintw(2, 1, enemy->name);
    mvprintw(2, 20, "Health - %i", enemy->health);
    refresh();
}

Player set_enemy(Player * player) {
    Player enemy;
    int col;
    int row;
    generateName(&(enemy.name));
    getmaxyx(stdscr, row, col);
    int count = 0;
    enemy.str = 1 + rand()%10;
    enemy.agil = 1 + rand()%10;
    enemy.intel = 1 + rand()%10;
    enemy.fire = 1 + rand()%10;
    enemy.ice = 1 + rand()%10;
    enemy.health = enemy.str*3;
    while(enemy.fire + enemy.intel - player->intel <= 0 &&
          enemy.fire + enemy.agil - player->intel <= 0 &&
          enemy.ice + enemy.agil - player->intel <= 0 &&
          count <= 50) {
        enemy.str = 1 + rand()%10;
        enemy.agil = 1 + rand()%10;
        enemy.intel = 1 + rand()%10;
        enemy.fire = 1 + rand()%10;
        enemy.ice = 1 + rand()%10;
        enemy.health = enemy.str*3;
        count++;
    }
    if(count >= 50) {
        clear();
        mvprintw(5, 5, "You too mighty! Congrats!");
        getch();
        refresh();
        upgrade(player);
    }
    //test
    /*
    enemy.str = 10;
    enemy.agil = 100;
    enemy.intel = 100;
    enemy.fire = 100;
    enemy.ice = 100;
    enemy.health = enemy.str*3;
    */
    enemy.col = 6;
    enemy.row = 14;
    return enemy;
}

void game(Player * player, Player * enemy) {
    int ch;
    char fire[] = "1. Fire magic";
    char ice[] = "2. Ice magic";
    char fireBall[] = "1. Fireball";
    char fireIgnition[] = "2. Ignition";
    char iceFrost[] = "1. Frost him";
    char iceHeal[] = "2. Heal";
    mvprintw(20, 0, fire);
    mvprintw(21, 0, ice);
    refresh();
    while(true) {
        clearMenu();
        mvprintw(20, 0, fire);
        mvprintw(21, 0, ice);
        printPlayers(player, enemy);
        if(enemy->health <= 0) {
            mvaddch(enemy->col, enemy->row, 'X');
            mvprintw(10, 10, "YOU WIN!!1111");
            getch();
            upgrade(player);
            break;
        }
        if(player->health <= 0) {
            mvaddch(player->col, player->row, 'X');
            mvprintw(10, 10, "YOU LOSE!!1111");
            getch();
            break;
        }
        ch = getch();
        bool flag = 0;
        switch(ch) {
            case '1':
                while(true) {
                if(flag == 1)
                    break;
                clearMenu();
                mvprintw(20, 0, fireBall);
                mvprintw(21, 0, fireIgnition);
                if(ch == 'b')
                    flag = 1;
                ch = getch();
                switch(ch) {
                    case '1':
                        useMagic(FIREBALL, player, enemy);
                        flag = 1;
                        break;
                    case '2':
                        useMagic(IGNITION, player, enemy);
                        flag = 1;
                        break;
                    default:
                        break;
                }
                }
                break;
            case '2':
                clearMenu();
                mvprintw(20, 0, iceFrost);
                mvprintw(21, 0, iceHeal);
                if(ch == 'b')
                    flag = 1;
                ch = getch();
                switch(ch) {
                    case '1':
                        useMagic(FROST, player, enemy);
                        flag = 1;
                        break;
                    case '2':
                        useMagic(HEAL, player, enemy);
                        flag = 1;
                        break;
                    default:
                        break;
                }
                break;
        }
        if(ch == 'q')
            break;
    }
}

void stage(Player * player){
    int foreground, background;
    set_map();
    Player enemy = set_enemy(player);
    foreground = rand()%8;
    background = rand()%8;
    while(foreground == background) {
        foreground = rand()%8;
        background = rand()%8;
    }
    init_pair(GAME_PAIR, foreground, background);
    attron(COLOR_PAIR(GAME_PAIR));
    mvaddch(enemy.col, enemy.row, '@');
    mvaddch(enemy.col, enemy.row+1, '\\');
    mvaddch(player->col, player->row, '@');
    mvaddch(player->col, player->row+1, '/');
    refresh();
    game(player, &enemy);
}
