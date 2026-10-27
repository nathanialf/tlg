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
