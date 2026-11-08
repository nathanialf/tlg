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
