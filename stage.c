#include "stage.h"
#include "nextLevel.h"
#include <panel.h>
#include <string.h>

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
        mvaddch(player.col-5, player.row-1, magic);
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(player.col-4, player.row-2, magic);
        mvaddch(player.col-5, player.row-1, '.');
        refresh();
        delay_output(ANIMATIONDELAY);
        mvaddch(player.col-4, player.row-2, '.');
    }
    refresh();
}

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
    }
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
        default:
            break;
    }
    if(enemy->health > 0)
        enemyTurn(player, enemy);
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
    //strcpy(name, player->name);
    mvprintw(1, 1, player->name);
    mvprintw(1, 20, "Health - %i", player->health);
    mvprintw(2, 1, enemy->name);
    mvprintw(2, 20, "Health - %i", enemy->health);
    refresh();
}

Player set_enemy() {
    Player enemy;
    int col;
    int row;
    char name[] = "Zlo";
    strcpy(enemy.name, name);
    getmaxyx(stdscr, row, col);
    /*
    enemy.str = 1 + rand()%10;
    enemy.agil = 1 + rand()%10;
    enemy.intel = 1 + rand()%10;
    enemy.fire = 1 + rand()%10;
    enemy.ice = 1 + rand()%10;
    enemy.health = enemy.str*3;
    */
    //test

    enemy.str = 10;
    enemy.agil = 1;
    enemy.intel = 1;
    enemy.fire = 1;
    enemy.ice = 1;
    enemy.health = enemy.str*3;

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
    set_map();
    Player enemy = set_enemy();
    init_pair(PLAYER, COLOR_BLACK, BACKGROUND);
    attron(COLOR_PAIR(PLAYER));
    mvaddch(enemy.col, enemy.row, '@');
    mvaddch(enemy.col, enemy.row+1, '\\');
    mvaddch(player->col, player->row, '@');
    mvaddch(player->col, player->row+1, '/');
    refresh();
    game(player, &enemy);
}
