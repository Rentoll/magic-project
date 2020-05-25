#ifndef MAGIC
#define MAGIC
#include "init.h"
#define ANIMATIONDELAY 500
#define FIREBALL 1
#define IGNITION 2
#define FROST   3
#define HEAL    4
void heal(Player * player); //healing effect and animation
void useMagic(int magicType, Player * player, Player * enemy); //applying magic effect
void sendMagic(int magicType, Player player, bool deflected); //animation of magic

#endif // MAGIC
