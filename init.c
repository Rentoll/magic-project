#include "init.h"
#include <curses.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

Player init_game() {
    char mesgName[] = "Enter a name: ";
    char mesgChar[] = "Choice your stats";
    int row;
    int col;
    char ch;
    srand(time(NULL));
    initscr();
    cbreak();
    start_color();
	start_color();
    printw("Welcome to the game.\nPress any key to start.\n");
    refresh();
    getch();
    clear();
    Player player;
    char str[150];
    getmaxyx(stdscr, row, col);
    mvprintw(0,0, "%s", mesgName);
    getstr(player.name);
    clear();
    handleLevel(&player);
    clear();
    curs_set(false);
    noecho();
    return player;
}

void handleLevel(Player * player) {
    int ch;
    int points = 25;
    player->col = 13;
    player->row = 14;
    player->str = 1;
    player->agil = 1;
    player->intel = 1;
    player->fire = 1;
    player->ice = 1;
    while(points > 0) {
        clear();
        mvprintw(0, 0, "Greetings! You have %i skill points.", points);
        mvprintw(1, 0, "1. Strength - %i points (Health - %i)", player->str, player->str*3);
        mvprintw(2, 0, "2. Agility - %i points ", player->agil);
        mvprintw(3, 0, "3. Intellect - %i points ", player->intel);
        mvprintw(4, 0, "4. Fire magic - %i points ", player->fire);
        mvprintw(5, 0, "5. Ice magic - %i points ", player->ice);
        refresh();
        ch = getch();
        switch(ch) {
            case '1':
                if(player->str < 10){
                    player->str++;
                    points--;
                }
                break;
            case '2':
                if(player->agil < 10) {
                    player->agil++;
                    points--;
                }
                break;
            case '3':
                if(player->intel < 10) {
                    player->intel++;
                    points--;
                }
                break;
            case '4':
                if(player->fire < 10) {
                    player->fire++;
                    points--;
                }
                break;
            case '5':
                if(player->ice < 10) {
                    player->ice++;
                    points--;
                }
                break;
            default:
                break;
        }
    }
    player->health = player->str*3;
}
