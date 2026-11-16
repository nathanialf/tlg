/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 17 of the vtable at 0x16b0fb0 (its pointer at
 * 0x16b1048) and, through the thunk 0x137e100 (this - 0x140, the body
 * inlined into it), slot 0 of the base at +0x140 (its pointer at 0x16b10b0):
 * when the object at +0x148 is set and its slot 7 returns nonzero, calls the
 * class's slot 14 (FUN_0137e190) and returns that value; else 0.
 * FUN_01396750 is the same method of the class at 0x16cf260. */
int Object016b0fb0::FUN_0137e100()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            slot14();
            result = value;
        }
    }
    return result;
}
