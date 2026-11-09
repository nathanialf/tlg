/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 4 of the vtable at 0x16bf4e0 (its pointer at 0x16bf510),
 * the vtable stored by FUN_00f59e00, whose sibling vtables hold FUN_00f68e00
 * and FUN_00f68e10 to FUN_00f68e50 in the same slot. It calls FUN_00f67000
 * with the object, 0 and 5 as a tail call (FUN_00f68e00 passes 1 and 3).
 * FUN_00f67000 keeps the second as a 32-bit value it compares with zero and
 * the third as a 64-bit one (spilled with movq at 0xf6701e); their meaning and
 * the return type are not traced. Class and method unknown. */
#include "tlg_types.h"

struct Object00f67000; /* derived name */

void FUN_00f67000(Object00f67000 *self, int, u64); /* derived name */

void FUN_00f68e20(Object00f67000 *self) /* derived name */
{
    FUN_00f67000(self, 0, 5);
}
