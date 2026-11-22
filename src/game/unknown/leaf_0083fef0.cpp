/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slot 12 of the class at 0x16aed28: slot 47 with 0, then
 * the int at +0x2c0 copied to +0x554 and, when it is positive, bit 0 of the
 * bits at +0x4f8 cleared (`and byte [rbx+0x4f8], 0xfe`) */
void Object016aed28::slot12()
{
    slot47(0);
    unknown554 = unknown2c0;
    if (unknown554 > 0)
        unknown4f8 &= ~1u;
}
