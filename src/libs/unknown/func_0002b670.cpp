/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the values B of the record's entries, at most four, set
 * from the array scaled by the info's +0x110 and negated. */
void FUN_0002b670(const Info0002b180 *info, const float *values, Pair08Owner *self)
{
    const int count = self->count < 4 ? self->count : 4;
    const float scale = info->value110;
    Pair08Entry *entry = reinterpret_cast<Pair08Entry *>(self + 1);
    for (int i = 0; i < count; i++, entry++) {
        lane(entry->vectorB, 3) = -(scale * values[i]);
    }
}
