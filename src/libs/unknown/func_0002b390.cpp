/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: sets or clears bit 2 of the record's flags (the bool the
 * forwarder FUN_000348d0 passes on widened). */
void FUN_0002b390(Pair08Owner *self, bool enable)
{
    if (enable) {
        self->flags |= 4;
    } else {
        self->flags &= ~4;
    }
}
