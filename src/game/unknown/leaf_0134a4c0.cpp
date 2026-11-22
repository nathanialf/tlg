/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slots 25, 26, 32 and 33 of the class at 0x16aed28: a
 * name assigned (FUN_0134a450: the one at +0x540, the shape marked changed;
 * FUN_0134a4c0: +0x54c; FUN_0134a580: +0x544; FUN_0134a5f0: +0x548) */
void Object016aed28::slot26(const Name &name)
{
    name54c = name;
}

void Object016aed28::slot32(const Name &name)
{
    name544 = name;
}

void Object016aed28::slot33(const Name &name)
{
    name548 = name;
}

void Object016aed28::slot25(const Name &name)
{
    name540 = name;
    flags |= 0x10;
}
