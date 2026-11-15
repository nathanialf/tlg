/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 3 of the base at +0x30 (its thunk 0x13747a0, this -
 * 0x30, the body inlined into it): the int at +0xac, doubled plus two when the
 * int at +0x380 is set, and at least 4. */
int Class16cc478::FUN_01376350() const
{
    if (unknown380) {
        int count = 2 * unknownac + 2;
        return count < 4 ? 4 : count;
    }
    return unknownac < 4 ? 4 : unknownac;
}
