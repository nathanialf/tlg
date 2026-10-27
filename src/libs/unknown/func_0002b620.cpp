/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the values B of the record's entries, at most four, scaled
 * by the info's +0x130 and the first lane of its +0x40 and negated. */
void FUN_0002b620(const Pair08Owner *self, const Info0002b180 *info, float *out)
{
    const int count = self->count < 4 ? self->count : 4;
    const float scale = info->value130 * lane(info->vector40, 0);
    const Pair08Entry *entry = reinterpret_cast<const Pair08Entry *>(self + 1);
    for (int i = 0; i < count; i++, entry++) {
        out[i] = -(scale * component<3>(entry->vectorB));
    }
}
