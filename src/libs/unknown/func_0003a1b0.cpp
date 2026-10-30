/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516::FUN_0003a1b0(
    const hknpCollisionFilterContext &context, hknpCollisionFilterBodyIdPair *pairs,
    int numPairs) const /* derived name */
{
    hknpCollisionFilterBodyIdPair *out = pairs;
    const hknpCollisionFilterBodyIdPair *in = pairs;
    for (int i = 0; i < numPairs; i++, in++) {
        const hknpCollisionFilterBodyIdPair &pair = *in;
        const u32 infoA = context.bodies[pair.bodyIdA.value].collisionFilterInfo;
        const u32 infoB = context.bodies[pair.bodyIdB.value].collisionFilterInfo;
        if (isCollisionEnabled(infoA, infoB)) {
            *out = pair;
            out++;
        }
    }
    return int(out - pairs);
}
