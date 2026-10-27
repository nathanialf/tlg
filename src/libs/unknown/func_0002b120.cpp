/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: valueB of every entry scaled where it is positive; the
 * count is read again only after a store (0x2b152). */
void FUN_0002b120(Pair08Owner *self, float scale) /* derived name */
{
    Pair08Entry *entry = reinterpret_cast<Pair08Entry *>(self + 1);
    for (int i = 0; i < self->count; i++, entry++) {
        if (entry->valueB > 0.0f) {
            entry->valueB *= scale;
        }
    }
}
