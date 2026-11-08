/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 24 of 151 (539 bytes against 571). Two classes. (1) The base
// keeps the entries' storage and count in registers through the loop (the
// count stored each pass from a counter, `mov [rbp-0x48], r12d`, nothing
// reloaded after the reader's call 0x93830): BasicAA's isNonEscapingLocalObject
// (BasicAliasAnalysis.cpp:45-60, 703) holds for the local array only when its
// one escape, the call to 0x72400, passes it to a nocapture parameter, which
// FunctionAttrs infers only for a function defined in the unit: 0x72400 is
// this file's (measured with a throwaway non-capturing definition: the loop
// takes the base's form). (2) The local array's constructor stores the data,
// the capacity, then the local memory (Havok's order, as 0x1a1e80's), where
// the tree's LocalArray stores the local memory before the capacity for
// 0x1707d0 (NOTES "Round 73B", "Round 78A").

void FUN_00072740(hknpWorldContextPool::Context *context, void *argument2,
                  const hkBlockStream *caches, void *argument4, const void *argument5,
                  int argument6, void *argument7, void *argument8)
{
    LocalArray<BodyPairEntry000717d0> entries(caches->numTotalElements);
    hkBlockStreamReader reader;
    reader.FUN_000937c0(caches);
    for (const hknpCollisionCache *cache = static_cast<const hknpCollisionCache *>(reader.access());
         cache;
         cache = static_cast<const hknpCollisionCache *>(reader.advance(cache->sizeInQuads * 16))) {
        BodyPairEntry000717d0 &entry = *entries.expandByUnchecked(1);
        entry.bodyA.value = cache->key0;
        entry.bodyB.value = cache->key4;
        entry.cache = cache;
        const hkArray<hknpBody> &bodies = context->world->bodyManager.bodies;
        const hknpBody &bodyA = bodies[entry.bodyA.value];
        if (bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) {
            entry.value0 = bodies[entry.bodyB.value].indexIntoActiveListOrDeactivatedIslandId;
        } else {
            entry.value0 = bodyA.indexIntoActiveListOrDeactivatedIslandId;
        }
    }
    FUN_00072400(context, argument2, &entries, argument5, argument6, argument4, argument7,
                 argument8);
}
