#ifndef STAGE_H
#define STAGE_H
#include "init.h"
#define MAPSIZE 10
void set_map(); //������� �������� �������
void stage(Player * player);//������� ������������ set_map, set_enemy() � game()
Player set_enemy(); //�������������� ���������
void game(Player * player, Player * enemy); // �������� ����, ���������� ���� ����� � �� �����
void clearMenu(); //������� ���� ����������
void printPlayers(Player * player, Player * enemy); // ���� ������������ ����� � HP �����
#endif
