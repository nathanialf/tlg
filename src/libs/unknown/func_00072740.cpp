/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* A range started, and ended, in a block of its own: the writer moved to a
 * new block first when it has written to its current one. derived
 * names. */
static inline void startRangeInOwnBlock(hkBlockStreamRange *range, hkBlockStreamWriter *writer)
{
    writer->startNewBlockIfUsed();
    range->setStartPoint(writer);
}

static inline void endRangeInOwnBlock(hkBlockStreamRange *range, hkBlockStreamWriter *writer)
{
    writer->startNewBlockIfUsed();
    range->FUN_00092220(writer);
}

// NONMATCHING (claim pending): compiles equal (205 instructions, 828 bytes), not claimed because
// this unit instantiates the two sorts it calls, 0x72c10 and 0x72ab0, and the layout link
// places a unit's own unclaimed function only where its code equals the base's
// (tools/layout_link.py, resolve_symbol_address): both are drafts (func_00072c10.cpp,
// func_00072ab0.cpp). Claimed with them, under its mangled name.
void FUN_00072400(hknpWorldContextPool::Context *context, const ModifierSharedData *shared,
                  hkArray<BodyPairEntry000717d0> *entries, hknpDeactivatedIsland **islands,
                  int numIslands, hkBlockStream *childCacheStream, hkBlockStream *cacheStreamOut,
                  hkBlockStream *childCacheStreamOut)
{
    hkAlgorithm::quickSort(islands, numIslands, KeyLess00072c10());
    hkAlgorithm::quickSort(entries->data, entries->getSize(), Value0ThenKeyLess000717d0());

    hkBlockStreamWriter cacheWriter;
    cacheWriter.FUN_000938c0(context->cache258, cacheStreamOut);
    hkBlockStreamWriter childCacheWriter;
    childCacheWriter.FUN_000938c0(context->cache258, childCacheStreamOut);

    const int numEntries = entries->getSize();
    int entryIndex = 0;
    for (int i = 0; i < numIslands; i++) {
        hknpDeactivatedIsland *island = islands[i];
        if (!island) {
            continue;
        }
        /* An island that keeps its blocks apart starts each range in a
         * block of its own. */
        if (island->usesOwnBlocks) {
            startRangeInOwnBlock(&island->cacheRange, &cacheWriter);
            startRangeInOwnBlock(&island->childCacheRange, &childCacheWriter);
        } else {
            island->cacheRange.setStartPoint(&cacheWriter);
            island->childCacheRange.setStartPoint(&childCacheWriter);
        }

        while (entryIndex < numEntries && (*entries)[entryIndex].value0 == island->islandId) {
            FUN_000636c0(context, shared, context->world->unknown500[0] != 0,
                         (*entries)[entryIndex].cache, childCacheStream, &cacheWriter,
                         &childCacheWriter, &island->droppedPairs);
            entryIndex++;
        }

        /* And ends them with their blocks. */
        if (island->usesOwnBlocks) {
            endRangeInOwnBlock(&island->cacheRange, &cacheWriter);
            endRangeInOwnBlock(&island->childCacheRange, &childCacheWriter);
        } else {
            island->cacheRange.FUN_00092220(&cacheWriter);
            island->childCacheRange.FUN_00092220(&childCacheWriter);
        }
    }
    childCacheWriter.FUN_00093a10();
    cacheWriter.FUN_00093a10();
}

// NONMATCHING: 196 of 199 (763 bytes, the size equal), D41's class only: the local array's
// constructor stores the data, the capacity, then the local memory (Havok's order: 0x721e3,
// 0x721ed, 0x721f0), where the tree's LocalArray stores the local memory before the capacity
// for 0x1707d0. Under the SDK order it compiles equal (199 instructions), as 0x72740 does.
// The entries stay in registers through the loop because 0x72400, the local array's one
// escape, is defined in this unit: FunctionAttrs marks its parameter nocapture, so BasicAA's
// isNonEscapingLocalObject holds (BasicAliasAnalysis.cpp:45-60, 703). The ids are read after
// the entry is taken and before either is stored (0x72277, 0x7227b, then 0x7227e).
void FUN_00072100(hknpWorldContextPool::Context *context, const ModifierSharedData *shared,
                  const hkArray<hkBlockStreamRange> *const *rangeArrays, int numRangeArrays,
                  hknpDeactivatedIsland **islands, int numIslands, hkBlockStream *childCacheStream,
                  hkBlockStream *cacheStreamOut, hkBlockStream *childCacheStreamOut)
{
    int numEntries = 0;
    for (int i = 0; i < numRangeArrays; i++) {
        const hkArray<hkBlockStreamRange> &ranges = *rangeArrays[i];
        for (int j = 0; j < ranges.getSize(); j++) {
            numEntries += ranges[j].numElements;
        }
    }
    LocalArray<BodyPairEntry000717d0> entries(numEntries);
    for (int i = 0; i < numRangeArrays; i++) {
        const hkArray<hkBlockStreamRange> &ranges = *rangeArrays[i];
        for (int j = 0; j < ranges.getSize(); j++) {
            hkBlockStreamReader reader;
            reader.FUN_000937f0(&ranges[j]);
            for (const hknpCollisionCache *cache =
                     static_cast<const hknpCollisionCache *>(reader.access());
                 cache; cache = static_cast<const hknpCollisionCache *>(
                            reader.advance(cache->sizeInQuads * 16))) {
                BodyPairEntry000717d0 &entry = *entries.expandByUnchecked(1);
                const hknpBodyId bodyIdA(cache->key0);
                const hknpBodyId bodyIdB(cache->key4);
                entry.bodyA = bodyIdA;
                entry.bodyB = bodyIdB;
                entry.cache = cache;
                const hkArray<hknpBody> &bodies = context->world->bodyManager.bodies;
                const hknpBody &bodyA = bodies[entry.bodyA.value];
                if (bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) {
                    entry.value0 =
                        bodies[entry.bodyB.value].indexIntoActiveListOrDeactivatedIslandId;
                } else {
                    entry.value0 = bodyA.indexIntoActiveListOrDeactivatedIslandId;
                }
            }
        }
    }
    FUN_00072400(context, shared, &entries, islands, numIslands, childCacheStream, cacheStreamOut,
                 childCacheStreamOut);
}

// NONMATCHING: 148 of 151 (571 bytes, the size equal), D41's class only (0x727db, 0x727e5,
// 0x727e8: the data, the capacity, then the local memory); equal (151 instructions) under the
// SDK order. As 0x72100: 0x72400 in this unit, the ids read before they are stored.
void FUN_00072740(hknpWorldContextPool::Context *context, const ModifierSharedData *shared,
                  const hkBlockStream *caches, hkBlockStream *childCacheStream,
                  hknpDeactivatedIsland **islands, int numIslands, hkBlockStream *cacheStreamOut,
                  hkBlockStream *childCacheStreamOut)
{
    LocalArray<BodyPairEntry000717d0> entries(caches->numTotalElements);
    hkBlockStreamReader reader;
    reader.FUN_000937c0(caches);
    for (const hknpCollisionCache *cache = static_cast<const hknpCollisionCache *>(reader.access());
         cache;
         cache = static_cast<const hknpCollisionCache *>(reader.advance(cache->sizeInQuads * 16))) {
        BodyPairEntry000717d0 &entry = *entries.expandByUnchecked(1);
        const hknpBodyId bodyIdA(cache->key0);
        const hknpBodyId bodyIdB(cache->key4);
        entry.bodyA = bodyIdA;
        entry.bodyB = bodyIdB;
        entry.cache = cache;
        const hkArray<hknpBody> &bodies = context->world->bodyManager.bodies;
        const hknpBody &bodyA = bodies[entry.bodyA.value];
        if (bodyA.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE)) {
            entry.value0 = bodies[entry.bodyB.value].indexIntoActiveListOrDeactivatedIslandId;
        } else {
            entry.value0 = bodyA.indexIntoActiveListOrDeactivatedIslandId;
        }
    }
    FUN_00072400(context, shared, &entries, islands, numIslands, childCacheStream, cacheStreamOut,
                 childCacheStreamOut);
}
