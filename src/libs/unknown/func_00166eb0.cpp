/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The map rebuilt at a new capacity, at least 8, from the allocator given:
 * every new slot emptied, the old entries inserted again, the old storage
 * given back unless the map did not own it; a failure when the allocator
 * has no room, the map as it was. derived name. */
hkResult hknpPairCollisionFilterMapPairFilterKeyOverrideType::FUN_00166eb0(AllocatorBase &allocator,
                                                                           int newCapacity)
{
    const int capacity = hkMath::max2(newCapacity, 8);
    const int oldHashMod = hashMod;
    const int oldNumElems = numElems;
    Pair *const oldElem = elem;
    Pair *const newElem = static_cast<Pair *>(allocator.blockAlloc(capacity * int(sizeof(Pair))));
    if (!newElem) {
        return HK_FAILURE;
    }
    elem = newElem;
    for (int i = 0; i < capacity; i++) {
        Pair &entry = elem[i];
        entry.key.bodyIdA = 0x7fffffff;
        entry.key.bodyIdB = 0x7fffffff;
    }
    numElems = 0;
    hashMod = capacity - 1;

    const int oldCapacity = oldHashMod + 1;
    for (int i = 0; i < oldCapacity; i++) {
        if (!isEmptyKey(oldElem[i].key)) {
            FUN_00166dc0(allocator, oldElem[i].key, oldElem[i].value);
        }
    }
    if ((oldNumElems & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(oldElem, oldCapacity * int(sizeof(Pair)));
    }
    return HK_SUCCESS;
}
