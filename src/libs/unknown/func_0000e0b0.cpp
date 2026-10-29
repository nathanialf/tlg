/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkSimpleLocalFrame::FUN_0000e0b0(hkLocalFrameGroup *newGroup)
{
    if (newGroup) {
        newGroup->addReference();
    }
    if (group) {
        group->removeReference();
    }
    group = newGroup;
}
