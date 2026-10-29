/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the base keeps the children array's address in a register
// (`lea r12, [r14+0x30]`), loads the count for the first walk only on its
// path, and leaves the name walk unrotated (its test block shared by the
// entry and the latch); here the count is loaded once at entry and reused as
// the second walk's guard, which is rotated. 5 of 51 instructions, 127 bytes
// against 142 (docs/NOTES.md, Round 51).
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
    for (; i < children.getSize(); i++) {
        hkMemoryResourceContainer *child = children[i];
        if (!childName || FUN_00017f40(childName, child->name.cString()) == 0) {
            return child;
        }
    }
    return 0;
}
