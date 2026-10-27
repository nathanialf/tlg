/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the twister's 624 words of state freed, when it has any. */
void FUN_00010690(MersenneTwister *self)
{
    if (self->state) {
        D_16dc070->temp58->blockFree(self->state, 624 * sizeof(u32));
        self->state = 0;
    }
}
