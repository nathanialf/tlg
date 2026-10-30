/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hknpPairCollisionFilterMapPairFilterKeyOverrideType::FUN_00166dc0(AllocatorBase &allocator,
                                                                      Key key, u32 value)
{
    if (numElems * 2 > hashMod) {
        FUN_00166eb0(allocator, hashMod * 2 + 2);
    }
    const u64 hashValue = ((u64(key.bodyIdA) << 32) | key.bodyIdB) * 0x9e3779b1;
    u32 i = u32(hashValue & u32(hashMod));
    int isNew = 1;
    for (; !isEmptyKey(elem[i].key); i = (i + 1) & hashMod) {
        if (equalKeys(elem[i].key, key)) {
            isNew = 0;
            break;
        }
    }
    numElems += isNew;
    elem[i].key = key;
    elem[i].value = value;
    return isNew;
}
