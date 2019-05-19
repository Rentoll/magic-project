#include "curses.h"
#include "store.h"
#include "init.h"


void printStore(Player * player) {
    int ch;
    mvprintw(0, 0, "Welcome to the store! Everything for 150 coins! You have %i coins\n", player->money);
    refresh();
    int equipment[] = {1, 1, 1, 1, 1};
    for(int i = 0; i < 5; i++) {
        if(player->storage[i])
            equipment[i] = 0;
    }
    while(true) {
        int place = 1;
        for(int i = 0; i < 5; i++) {
            if(equipment[i]) {
                printEquip(i, place);
                place++;
            }
        }
        ch = getch();
        break;
    }
}

void printEquip(int number, int place) {
    switch(number) {
        case 0:
            mvprintw(place, 0, "%i. Fire wand(+4 fire)", place);
            break;
        case 1:
            mvprintw(place, 0, "%i. Ice staff(+4 ice)", place);
            break;
        case 2:
            mvprintw(place, 0, "%i. Intelelgent cloak(+4 intel)", place);
            break;
        case 3:
            mvprintw(place, 0, "%i. Strength boots(+4 str)", place);
            break;
        case 4:
            mvprintw(place, 0, "%i. Something thing(+4)", place);
            break;
        default:
            break;
    }
    refresh();
}
