#include <panel.h>
#include <string.h>
#include "magic.h"
#include "enemyAi.h"

void heal(Player * player) {
    delay_output(ANIMATIONDELAY);
    mvaddch(player->col, player->row + 1, '%');
    mvaddch(player->col, player->row - 1, '%');
    mvaddch(player->col - 1, player->row, '%');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player->col, player->row + 1, '.');
    mvaddch(player->col, player->row - 1, '.');
    mvaddch(player->col - 1, player->row, '.');
    refresh();
    mvaddch(player->col, player->row + 1, '/');
}

void useMagic(int magicType, Player * player, Player * enemy) {
    int damage = 0;
    bool flag = false;
    switch(magicType) {
        case FIREBALL:
            damage = player->fire + player->intel - enemy->intel;
            if(damage < 0) {
                damage = 0;
                flag = true;
            }
            else
                enemy->health -= damage;
            sendMagic(FIREBALL, *player, flag);
            break;

        case IGNITION:
            damage = player->fire + player->agil - enemy->intel;
            if(damage < 0) {
                damage = 0;
                flag = true;
            }
            else
                enemy->health -= damage;
            sendMagic(IGNITION, *player, flag);
            break;

        case SUPERFIRE:
            damage = player->fire * 2 - enemy->intel;
            if(damage < 0) {
                damage = 0;
                flag = true;
            }
            else
                enemy->health -= damage;
            sendMagic(SUPERFIRE, *player, flag);
            break;

        case FROST:
            damage = player->ice + player->agil - enemy->intel;
            if(damage < 0) {
                damage = 0;
                flag = true;
            }
            else
                enemy->health -= damage;
            sendMagic(FROST, *player, flag);
            break;

        case HEAL:
            heal(player);
            if(player->health + player->ice < player->str * 3)
                player->health += player->intel;
            else
                player->health = player->str * 3;
            break;

        case SUPERICE:
            damage = player->ice * 2 - enemy->intel;
            if(damage < 0) {
                damage = 0;
                flag = true;
            }
            else
                enemy->health -= damage;
            sendMagic(SUPERICE, *player, flag);
            break;

        default:
            break;
    }
    if(enemy->health > 0)
        enemyTurn(player, enemy);
}

void sendMagic(int magicType, Player player, bool deflected){
    char magic;
    switch(magicType){
        case FIREBALL:
            magic = '*';
            break;
        case IGNITION:
            magic = '%';
            break;
        case FROST:
            magic = '+';
            break;
        case HEAL:
            heal(&player);
            break;
        case SUPERFIRE:
            magic = '$';
            break;
        case SUPERICE:
            magic = '|';
            break;
    }
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-1, player.row, magic);
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-2, player.row, magic);
    mvaddch(player.col-1, player.row, '.');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-3, player.row, magic);
    mvaddch(player.col-2, player.row, '.');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-4, player.row, magic);
    mvaddch(player.col-3, player.row, '.');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-5, player.row, magic);
    mvaddch(player.col-4, player.row, '.');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-6, player.row, magic);
    mvaddch(player.col-5, player.row, '.');
    refresh();
    delay_output(ANIMATIONDELAY);
    mvaddch(player.col-6, player.row, '.');
    if(deflected) {
        if(rand()%2 == 0) {
            mvaddch(player.col-5, player.row-1, magic);
            refresh();
            delay_output(ANIMATIONDELAY);
            mvaddch(player.col-4, player.row-2, magic);
            mvaddch(player.col-5, player.row-1, '.');
            refresh();
            delay_output(ANIMATIONDELAY);
            mvaddch(player.col-4, player.row-2, '.');
        }
        else {
            mvaddch(player.col-5, player.row+1, magic);
            refresh();
            delay_output(ANIMATIONDELAY);
            mvaddch(player.col-4, player.row+2, magic);
            mvaddch(player.col-5, player.row+1, '.');
            refresh();
            delay_output(ANIMATIONDELAY);
            mvaddch(player.col-4, player.row+2, '.');
        }
    }
    refresh();
}


