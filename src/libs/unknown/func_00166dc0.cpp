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

// NONMATCHING: 327 bytes against 575: the base inlines the map's insert
// (0x166dc0) here and at 0x16779b while 0x166eb0 still calls it; the debug
// opt (a78/llvm33dbg, every patch) prices it 230 against -O2's 225 at this
// call site (InlineCost.cpp, NumInstructionsSimplified 16, four arguments),
// one InstrCost over: the third witness of exactly 230 against 225 or 330
// against 325 after 0x277e0 and 0xacfc0 (NOTES "Round 78A"). With the hint
// (`inline`, 325) the insert inlines here but also into 0x166eb0, which the
// base's does not.
/* Defined beside the map's insert, which it holds inline (0x16753a to
 * 0x1675e2): the pair's count of disablings raised by one, then the
 * dynamic body of the two whose bounding radius is not the smaller has its
 * pairs rebuilt (the second unless the first is dynamic and the second
 * is not smaller). */
void hknpPairCollisionFilter::FUN_00167420(hknpWorld *world, u32 bodyIdA, u32 bodyIdB)
{
    hknpPairCollisionFilterMapPairFilterKeyOverrideType::Key key;
    key.bodyIdA = bodyIdA < bodyIdB ? bodyIdA : bodyIdB;
    key.bodyIdB = bodyIdA < bodyIdB ? bodyIdB : bodyIdA;
    int count = 1;
    const hkUlong it = disabledPairs.findKey(key);
    if (disabledPairs.isValid(it)) {
        count = disabledPairs.elem[it].value + 1;
    }
    disabledPairs.FUN_00166dc0(hkContainerHeapAllocator::get(), key, count);

    const hknpBody &bodyA = world->bodyManager.bodies[bodyIdA];
    u32 bodyId = bodyIdB;
    if (bodyA.flags & 2) {
        const hknpBody &bodyB = world->bodyManager.bodies[bodyIdB];
        if (!(bodyB.flags & 2) || !(bodyB.radiusOfComCenteredBoundingSphere.getReal() <
                                    bodyA.radiusOfComCenteredBoundingSphere.getReal())) {
            bodyId = bodyIdA;
        }
    }
    world->FUN_0005bf80(bodyId);
}
