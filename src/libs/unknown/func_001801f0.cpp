/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMemoryResourceContainer::FUN_001801f0(hkResourceHandle *handle) /* derived name */
{
    const int index = resourceHandles.indexOf(static_cast<hkMemoryResourceHandle *>(handle));
    if (index >= 0) {
        resourceHandles.removeAtAndCopy(index);
    }
}
