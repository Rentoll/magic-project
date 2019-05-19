#include <stdbool.h>
#include "nextLevel.h"

int check(int power) {
    if(power >= 10)
        return true;
    return false;
}

void upgrade(Player * player) {
    int ch;
    int flag = 0;
    player->health = player->str*3;
    char health[] = "1. Strength - ";
    char agil[] = "2. Agility - ";
    char intel[] = "3. Intellect - ";
    char fire[] = "4. Fire magic - ";
    char ice[] = "5. Ice magic - ";
    char upperMenu[] = " stats:";
    clear();
    if(check(player->str) && check(player->agil) && check(player->intel) && check(player->fire) && check(player->ice)) {
        clear();
        mvprintw(5, 5, "YOU COMPLETE THE GAME!!!!!");
        refresh();
        getch();
        theEnd();
    }
    else {
        mvprintw(0, 0, player->name);
        printw(upperMenu);
        mvprintw(1, 0, health);
        if(check(player->str))
            printw("MAX");
        else {
            printw("%i (Health - %i)", player->str, player->health);
        }
        mvprintw(2, 0, agil);
        if(check(player->agil))
            printw("MAX");
        else
            printw("%i", player->agil);
        mvprintw(3, 0, intel);
        if(check(player->intel))
            printw("MAX");
        else
            printw("%i", player->intel);
        mvprintw(4, 0, fire);
        if(check(player->fire))
            printw("MAX");
        else
            printw("%i", player->fire);
        mvprintw(5, 0, ice);
        if(check(player->ice))
            printw("MAX");
        else
            printw("%i", player->ice);
        refresh();
        while(true) {
            if(flag)
                break;
            ch = getch();
            switch(ch){
                case '1':
                    if(!check(player->str)) {
                        player->str++;
                        flag = 1;
                    }
                    break;
                case '2':
                    if(!check(player->agil)) {
                        player->agil++;
                        flag = 1;
                    }
                    break;
                case '3':
                    if(!check(player->intel)) {
                        player->intel++;
                        flag = 1;
                    }
                    break;
                case '4':
                    if(!check(player->fire)) {
                        player->fire++;
                        flag = 1;
                    }
                    break;
                case '5':
                    if(!check(player->ice)) {
                        player->ice++;
                        flag = 1;
                    }
                    break;
                default:
                    break;
            }
        }
        clear();
        refresh();
        stage(player);
    }
}

int theEnd() {
    endwin();
    exit(0);
}
