/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516::FUN_0003a1b0(
    const hknpWorld &world, hknpBodyIdPair *pairs, int numPairs) const /* derived name */
{
    hknpBodyIdPair *out = pairs;
    const hknpBodyIdPair *in = pairs;
    for (int i = 0; i < numPairs; i++, in++) {
        const hknpBodyIdPair &pair = *in;
        const u32 infoA = world.bodyManager.bodies[pair.bodyIdA.value].collisionFilterInfo;
        const u32 infoB = world.bodyManager.bodies[pair.bodyIdB.value].collisionFilterInfo;
        if (isCollisionEnabled(infoA, infoB)) {
            *out = pair;
            out++;
        }
    }
    return int(out - pairs);
}
