#ifndef MAGIC
#define MAGIC
#include "init.h"
#define ANIMATIONDELAY 500
#define FIREBALL 1
#define IGNITION 2
#define FROST   3
#define HEAL    4
#define SUPERFIRE 5
#define SUPERICE 6
void heal(Player * player); //�������� � ������ ������� ������
void useMagic(int magicType, Player * player, Player * enemy); //���������� ������� ������������� ����� �������
void sendMagic(int magicType, Player player, bool deflected); //�������� �������������� ����� �������

#endif // MAGIC
