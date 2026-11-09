/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x8 and passes its int on to
 * FUN_013fae50 as a tail call; slot 3 of the vtable at 0x16d57d0 (its pointer
 * at 0x16d57f8), the vtable stored by FUN_01078df0 FUN_0107a1c0. FUN_013fae50
 * reads +0x98 and +0x28 of the same object and loops over the int as a count;
 * it returns nothing traced. The slot-3 method of the vtables of FUN_014328e0
 * stores the same pointer at +0x8 and its int at +0x9c. The pointer's target
 * is not traced. Class and method unknown. */
struct Target01404cc0; /* derived name */

struct Object01404cc0 { /* derived name */
    u8 unknown0[0x8];
    Target01404cc0 *unknown8;
};

void FUN_013fae50(Object01404cc0 *self, int count); /* derived name */

void FUN_01404cc0(Object01404cc0 *self, Target01404cc0 *target, int count) /* derived name */
{
    self->unknown8 = target;
    FUN_013fae50(self, count);
}
