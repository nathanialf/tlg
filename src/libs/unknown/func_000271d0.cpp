/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: whether element a comes before element b in a vertex
 * format's canonical order. */
bool FUN_000271d0(const hkVertexFormat::Element &a, const hkVertexFormat::Element &b)
{
    return a.usage < b.usage || (a.usage == b.usage && a.subUsage < b.subUsage);
}
