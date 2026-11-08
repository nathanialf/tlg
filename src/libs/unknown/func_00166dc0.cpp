/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 552 bytes against 575 (17 of 159): the structure is the
 * base's (the insert inline here, its copy in the resize unit; the count
 * read by the map's own probe with the found block's value, 1 preset; the
 * count returned), the residual greedy's: the base gives the hash index
 * eax and the modulus r11d, the map's address r12 and the filter r14 (then
 * spilled to [rbp-0x38] for the count), the frame 0x38; here the index is
 * ebx, the two pointers swapped, a copy block `mov rdi, r10` on the probe's
 * exits and the found block placed inline, not after the return. */
/* The map's insert held inline (0x16753a to 0x1675e2): the pair's count
 * of disablings raised by one, then the dynamic body of the two whose
 * bounding radius is not the smaller has its pairs rebuilt (the second
 * unless the first is dynamic and the second is not smaller); the new
 * count returned (0x16763b). */
int hknpPairCollisionFilter::FUN_00167420(hknpWorld *world, u32 bodyIdA, u32 bodyIdB)
{
    hknpPairCollisionFilterMapPairFilterKeyOverrideType::Key key;
    key.bodyIdA = bodyIdA < bodyIdB ? bodyIdA : bodyIdB;
    key.bodyIdB = bodyIdA < bodyIdB ? bodyIdB : bodyIdA;
    const int count = disabledPairs.getWithDefault(key, 0) + 1;
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
    return count;
}

// NONMATCHING: 10 lines of the side by side differ, the code the base's but for two register
// classes: the count's probe carries the slot's entry in rax and its index in r14 (0x167719
// to 0x167760) where this compile reuses the entry's register for the shift and keeps the
// index in rax; and the first body's flags are tested as `and edx, 3` (0x1678db, an AND whose
// value has a second use in the base's DAG) where this tests the low byte. The key's larger id
// is written first: the other order gives the two ids each other's registers (r13 and r15).
/* The reverse of the disabling: the pair's count of disablings lowered by
 * one when the map holds it; at zero the entry is removed and, when both
 * bodies are in the world and their boxes meet, the pair's collision
 * caches are rebuilt. The new count returned. */
int hknpPairCollisionFilter::FUN_00167660(hknpWorld *world, u32 bodyIdA, u32 bodyIdB, int mode)
{
    hknpPairCollisionFilterMapPairFilterKeyOverrideType::Key key;
    key.bodyIdB = bodyIdA < bodyIdB ? bodyIdB : bodyIdA;
    key.bodyIdA = bodyIdA < bodyIdB ? bodyIdA : bodyIdB;
    int count = disabledPairs.getWithDefault(key, 0);
    if (count == 0) {
        return 0;
    }
    count--;
    if (count != 0) {
        disabledPairs.FUN_00166dc0(hkContainerHeapAllocator::get(), key, count);
        return count;
    }
    const hkUlong it = disabledPairs.findKey(key);
    if (disabledPairs.isValid(it)) {
        disabledPairs.FUN_00166fe0(it);
    }
    const hkArray<hknpBody> &bodies = world->bodyManager.bodies;
    if (bodyIdA != 0x7fffffff && u32(bodies.getCapacity()) > bodyIdA && bodyIdB != 0x7fffffff &&
        (bodies[bodyIdA].flags & (hknpBody::IS_STATIC | hknpBody::IS_DYNAMIC)) &&
        u32(bodies.getCapacity()) > bodyIdB &&
        (bodies[bodyIdB].flags & (hknpBody::IS_STATIC | hknpBody::IS_DYNAMIC))) {
        const hkAabb16 &aabbA = world->bodyManager.previousAabbs.data[bodyIdA];
        const hkAabb16 &aabbB = world->bodyManager.previousAabbs.data[bodyIdB];
        if (!aabbA.disjoint(aabbB)) {
            hknpBodyIdPair pair;
            pair.bodyIdA.value = bodyIdA;
            pair.bodyIdB.value = bodyIdB;
            world->FUN_0005c120(&pair, 1, mode);
        }
    }
    return 0;
}
