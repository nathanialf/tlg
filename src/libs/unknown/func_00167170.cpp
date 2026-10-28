/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpPairCollisionFilterMapPairFilterKeyOverrideType::FUN_00167170(AllocatorBase &allocator)
{
    clear();
    if ((numElems & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(elem, sizeof(Pair) * (hashMod + 1));
    }
    elem = 0;
    numElems = 0;
    hashMod = -1;
}
