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
    srand(time(NULL));
    Player player = init_game();
    stage(&player);
    return 0;
}
