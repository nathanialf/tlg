/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 13 of the vtable at 0x16cc478 and, through the thunk
 * 0x1374700 (this - 0x10, the body inlined into it), slot 0 of the base at
 * +0x10: when the object at +0x18 is set and its slot 7 returns nonzero, calls
 * the class's slot 6 (FUN_01376230) and returns that value; else 0. */
int Class16cc478::FUN_01374700()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            FUN_01376230();
            result = value;
        }
    }
    return result;
}
