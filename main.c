#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "init.h"
#include "stage.h"




//------------------------
#define SIZE 10
//------------------------

int main(){
    Player player = init_game();
    stage(&player);
    endwin();
    return 0;
}
