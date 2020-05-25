#include <curses.h>
#include "init.h"
#include "stage.h"

int main(){
    srand(time(NULL));
    Player player = init_game();
    stage(&player);
    return 0;
}
