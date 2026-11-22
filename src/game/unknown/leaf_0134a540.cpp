/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slot 28 of the class at 0x16aed28: the shape stored, the shape marked changed */
void Object016aed28::slot28(const u32 *value)
{
    unknown4f4 = *value;
    flags |= 0x10;
}
