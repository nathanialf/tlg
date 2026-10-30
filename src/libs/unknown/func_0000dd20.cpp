/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkLocalFrame::FUN_0000dd20(hkArray<hkLocalFrame *> &descendants,
                                AllocatorBase &allocator) const
{
    if (numChildFrames()) {
        for (int i = 0; i < numChildFrames(); i++) {
            hkLocalFrame *child = childFrame(i);
            if (child) {
                descendants.pushBack(allocator, child);
                child->FUN_0000dd20(descendants, allocator);
            }
        }
    }
}
