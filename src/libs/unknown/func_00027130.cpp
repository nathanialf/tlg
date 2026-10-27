/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hkVertexFormat::FUN_00027130(ComponentUsage usage, int subUsage) const
{
    for (int i = 0; i < numElements; i++) {
        const Element &element = elements[i];
        if (element.usage == usage && element.subUsage == subUsage) {
            return i;
        }
    }
    return -1;
}

/* derived name: an element added at the end when there is room and the
 * format has none of its usage and sub-usage yet (the search above,
 * inlined). */
void hkVertexFormat::FUN_000271f0(const Element &element)
{
    if (numElements >= 32) {
        return;
    }
    if (FUN_00027130(element.usage, element.subUsage) >= 0) {
        return;
    }
    elements[numElements++] = element;
}
