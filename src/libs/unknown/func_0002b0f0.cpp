/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: valueA of every entry scaled, the entries walked from the
 * first, which follows the owner's own bytes. */
void FUN_0002b0f0(Pair08Owner *self, float scale) /* derived name */
{
    Pair08Entry *entry = reinterpret_cast<Pair08Entry *>(self + 1);
    for (int i = 0; i < self->count; i++, entry++) {
        entry->valueA *= scale;
    }
}
