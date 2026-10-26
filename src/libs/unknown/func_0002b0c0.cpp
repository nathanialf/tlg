/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: sets the mode and the float, resets the byte at +0x1c, and
 * recomputes bits 3 and 5 of the first flags: bit 3 cleared, bit 5 set for
 * modes 2 and 3 when both ints are set. */
void FUN_0002b0c0(Pair08Owner *self, int mode, float value) /* derived name */
{
    self->flags0 &= ~8;
    if ((mode == 2 || mode == 3) && self->value10 != 0 && self->value14 != 0) {
        self->flags0 |= 0x20;
    }
    self->mode = mode;
    self->value1c = 0xff;
    self->value18 = value;
}
