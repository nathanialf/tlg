/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slot 30 of the class at 0x16aed28: the radius stored, the shape marked changed */
void Object016aed28::slot30(const float *value)
{
    unknown508 = *value;
    flags |= 0x10;
}
