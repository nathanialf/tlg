/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_00199b00(const hknpWorld *world, const hknpBody *bodyA, const hknpBody *bodyB,
                  hkBlockStreamWriter *writer) /* derived name */
{
    ConvexCompositeCache00199b00 *cache = static_cast<ConvexCompositeCache00199b00 *>(
        writer->reserve(sizeof(ConvexCompositeCache00199b00)));
    hkString::memSet16(cache, &D_14b2060[2], sizeof(*cache) / 16);
    const CollisionCache001785a0::Header header = {4, sizeof(*cache) / 16};
    cache->header = header;
    memset(&cache->unknownA, 0, 6);
    cache->childCacheRange.startBlock = HK_NULL;
    cache->childCacheRange.numElements = 0;
    cache->aabb.FUN_0014a1f0();
    cache->unknown14 = 0;
    cache->unknown10 = 0;
    cache->bodyIdA = bodyA->id;
    cache->bodyIdB = bodyB->id;
    const hknpBodyQuality &qualityA = world->qualityLibrary->qualities[bodyA->qualityId];
    const hknpBodyQuality &qualityB = world->qualityLibrary->qualities[bodyB->qualityId];
    u32 qualityFlags;
    if (qualityA.priority < qualityB.priority) {
        qualityFlags = qualityA.supportedFlags & qualityB.requestedFlags;
    } else {
        qualityFlags = qualityB.supportedFlags & qualityA.requestedFlags;
    }
    cache->unknownC = u16(qualityFlags);
    writer->advance(sizeof(ConvexCompositeCache00199b00));
}
