/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: resets the lock's record to -15 and a zero count, unless
 * its count is non-negative and the pointer at 0x57b7b90 is set. */
void FUN_00006b90(Record00006b90 *self) /* derived name */
{
    if (self->count < 0 || !D_57b7b90) {
        self->value = -15;
        self->count = 0;
    }
}
