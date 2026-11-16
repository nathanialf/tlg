/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* derived name: slot 2 of the base class (0x16d3ad0), the fade's update of
 * its entries (func_00f6d1a0.cpp), called on the object directly */
void FUN_013d4610(Object016d3ad0 *self); /* derived name */

/* FUN_00f66fd0: slot 2, the key function: the base's slot 2, then the
 * vector at +0x110 and the int at +0x124 cleared. FUN_00f66e00 (D1) and
 * FUN_00f66ef0 (D0), the implicit destructor, are emitted with it; the base
 * class's inline destructor (FUN_013d65a0, FUN_013d6640) with them. */
void Object016ca148::slot2()
{
    FUN_013d4610(this);
    unknown110 = _mm_setzero_ps();
    unknown124 = 0;
}
