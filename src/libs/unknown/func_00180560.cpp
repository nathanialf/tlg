/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMemoryResourceContainer::FUN_00180560(hkMemoryResourceContainer *child)
{
    const int index = children.indexOf(child);
    if (index >= 0) {
        children.removeAt(index);
    }
}
