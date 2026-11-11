/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 10 of the vtable at 0x16a9990: records at +0x98 whether
 * the int at +0x90 is set and differs from the one kept at +0x94, then keeps
 * it there. Class and method unknown. */
struct Object0042d600 { /* derived name */
    u8 unknown0[0x90];
    int current;  /* +0x90, derived name */
    int previous; /* +0x94, derived name */
    int changed;  /* +0x98, derived name */
};

void FUN_0042d600(Object0042d600 *self) /* derived name */
{
    int current = self->current;
    self->changed = current != 0 && self->previous != current;
    self->previous = current;
}
