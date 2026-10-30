/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkSimpleLocalFrame::~hkSimpleLocalFrame()
{
    const int numChildren = children.getSize();
    for (int i = 0; i < numChildren; i++) {
        children[i]->removeReference();
    }
    if (group) {
        group->removeReference();
    }
}
