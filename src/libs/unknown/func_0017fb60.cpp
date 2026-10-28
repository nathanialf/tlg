/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkMemoryResourceContainer's finish constructor: the name finished out of
 * line; a loaded container's children get their parent back. */
hkMemoryResourceContainer::hkMemoryResourceContainer(hkFinishLoadedObjectFlag flag)
    : hkResourceContainer(flag), name(flag), resourceHandles(flag), children(flag)
{
    if (flag.finishing) {
        for (int i = 0; i < children.getSize(); i++) {
            children[i]->parent = this;
        }
    }
}
