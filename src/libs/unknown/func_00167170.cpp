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

/* derived name: slot 5 of hknpPairCollisionFilter's vtable (0x16a5300), the
 * class's key function: the pairs the child filter keeps, when there is
 * one, then those not among the disabled pairs (each looked up smaller id
 * first) kept in place; how many are left. */
int hknpPairCollisionFilter::FUN_001679a0(const hknpCollisionFilterContext &context,
                                          hknpCollisionFilterBodyIdPair *pairs, int numPairs) const
{
    if (childFilter) {
        numPairs = childFilter->FUN_001679a0(context, pairs, numPairs);
    }
    hknpCollisionFilterBodyIdPair *out = pairs;
    const hknpCollisionFilterBodyIdPair *in = pairs;
    for (int i = 0; i < numPairs; i++, in++) {
        const hknpCollisionFilterBodyIdPair &pair = *in;
        hknpPairCollisionFilterMapPairFilterKeyOverrideType::Key key;
        const u32 a = pair.bodyIdA.value;
        const u32 b = pair.bodyIdB.value;
        key.bodyIdB = a < b ? b : a;
        key.bodyIdA = a < b ? a : b;
        if (!disabledPairs.isValid(disabledPairs.findKey(key))) {
            *out = pair;
            out++;
        }
    }
    return int(out - pairs);
}

void FUN_00158a30(hknpPairCollisionFilterMapPairFilterKeyOverrideType *self) {}
