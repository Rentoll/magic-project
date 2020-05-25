#include "init.h"
#include "magic.h"

void enemyTurn(Player * player, Player * enemy) {
    int magicType;
    int damage = 0;
    bool deflected = false;
    char magic;
    if(enemy->health == enemy->str*3)
        magicType = 1 + rand() % 3;
    else
        magicType = 1 + rand() % 4;
    switch(magicType){
        case FIREBALL:
            magic = '*';
            damage = enemy->fire + enemy->intel - player->intel;
            if(damage < 0) {
                damage = 0;
                deflected = true;
            }
            else
                player->health -= damage;
            break;
        case IGNITION:
            magic = '%';
            damage = enemy->fire + enemy->agil - player->intel;
            if(damage < 0) {
                damage = 0;
                deflected = true;
            }
            else
                player->health -= damage;
            break;
        case FROST:
            magic = '+';
            damage = enemy->ice + enemy->agil - player->intel;
            if(damage < 0) {
                damage = 0;
                deflected = true;
            }
            else
                player->health -= damage;
            break;
        case HEAL:
            if(enemy->health + enemy->ice < enemy->str * 3)
                enemy->health += enemy->intel;
            else
                enemy->health = enemy->str * 3;
            break;
    }
    if(magicType == HEAL) {
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col, enemy->row + 1, '%');
        mvaddch(enemy->col, enemy->row - 1, '%');
        mvaddch(enemy->col + 1, enemy->row, '%');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col, enemy->row + 1, '.');
        mvaddch(enemy->col, enemy->row - 1, '.');
        mvaddch(enemy->col + 1, enemy->row, '.');
        refresh();
        mvaddch(enemy->col, enemy->row + 1, '\\');
    }
    else{
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+1, enemy->row, magic);
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+2, enemy->row, magic);
        mvaddch(enemy->col+1, enemy->row, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+3, enemy->row, magic);
        mvaddch(enemy->col+2, enemy->row, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+4, enemy->row, magic);
        mvaddch(enemy->col+3, enemy->row, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+5, enemy->row, magic);
        mvaddch(enemy->col+4, enemy->row, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+6, enemy->row, magic);
        mvaddch(enemy->col+5, enemy->row, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(enemy->col+6, enemy->row, '.');
        refresh();
        if(deflected) {
            if(rand()%2 == 0) {
                mvaddch(enemy->col+5, enemy->row+1, magic);
                refresh();
                delay_output(ANIMATIONDELAY);
                mvaddch(enemy->col+4, enemy->row+2, magic);
                mvaddch(enemy->col+5, enemy->row+1, '.');
                refresh();
                delay_output(ANIMATIONDELAY);
                mvaddch(enemy->col+4, enemy->row+2, '.');
                refresh();
            }
            else {
                mvaddch(enemy->col+5, enemy->row-1, magic);
                refresh();
                delay_output(ANIMATIONDELAY);
                mvaddch(enemy->col+4, enemy->row-2, magic);
                mvaddch(enemy->col+5, enemy->row-1, '.');
                refresh();
                delay_output(ANIMATIONDELAY);
                mvaddch(enemy->col+4, enemy->row-2, '.');
                refresh();
            }
        }
    }
}
