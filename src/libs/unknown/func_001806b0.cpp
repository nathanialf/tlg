/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkMemoryResourceContainer *
hkMemoryResourceContainer::FUN_001806b0(const char *childName,
                                        const hkMemoryResourceContainer *previous)
{
    int i = 0;
    if (previous) {
        while (i < children.getSize()) {
            if (children[i++] == previous) {
                break;
            }
        }
    }
    while (i < children.getSize()) {
        hkMemoryResourceContainer *child = children[i++];
        if (!childName || FUN_00017f40(childName, child->name.cString()) == 0) {
            return child;
        }
    }
    return 0;
}
