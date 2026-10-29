/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMemoryResourceHandle::FUN_0017f3e0(const char *memberName)
{
    int i = 0;
    while (i < references.getSize()) {
        const hkMemoryResourceHandleExternalLink &link = references[i++];
        if (FUN_00017f40(link.memberName.cString(), memberName) == 0) {
            references.removeAt(i - 1);
            return;
        }
    }
}
