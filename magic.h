#ifndef MAGIC
#define MAGIC
#include "init.h"
#define ANIMATIONDELAY 500
#define FIREBALL 1
#define IGNITION 2
#define FROST   3
#define HEAL    4
void heal(Player * player); //анимация и эффект лечения игрока
void useMagic(int magicType, Player * player, Player * enemy); //применение эффекта использование магии игроком
void sendMagic(int magicType, Player player, bool deflected); //анимация использованной магии игроком

#endif // MAGIC
