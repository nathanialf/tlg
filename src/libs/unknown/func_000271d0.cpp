/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: whether element a comes before element b in a vertex
 * format's canonical order. */
bool FUN_000271d0(const hkVertexFormat::Element &a, const hkVertexFormat::Element &b)
{
    return a.usage < b.usage || (a.usage == b.usage && a.subUsage < b.subUsage);
}

/* derived name: the elements put in canonical order (by usage, then by
 * sub-usage), sorted only when two neighbours are out of that order (the
 * sort takes this file's order by address). */
void hkVertexFormat::FUN_00027180()
{
    for (int i = 1; i < numElements; i++) {
        const Element &prev = elements[i - 1];
        const Element &cur = elements[i];
        if (prev.usage > cur.usage || (prev.usage >= cur.usage && prev.subUsage >= cur.subUsage)) {
            FUN_00026f20(elements, 0, numElements - 1, FUN_000271d0);
            return;
        }
    }
}
