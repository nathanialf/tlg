/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: slot 13 of the vtable at 0x16cf260 (its pointer at 0x16cf2d8)
 * and, through the thunk 0x1395bd0 (this - 0x10, the body inlined into it),
 * slot 0 of the base at +0x10: when the object at +0x18 is set and its slot 7
 * returns nonzero, calls the class's slot 7 (FUN_01395df0) and returns that
 * value; else 0. FUN_0137ba00 is the same method of the class at 0x16cc478. */
int Object01395de0::FUN_01395bd0()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            FUN_01395df0();
            result = value;
        }
    }
    return result;
}
