/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slot 35 of the class at 0x16aed28: the bits at +0x4f8 stored, the shape marked changed */
void Object016aed28::slot35(u32 bits)
{
    unknown4f8 = bits;
    flags |= 0x10;
}
