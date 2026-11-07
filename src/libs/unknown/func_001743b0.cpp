/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_001743b0(const hknpWorld *world, const hknpBody *bodyA, const hknpBody *bodyB,
                  hkBlockStreamWriter *writer) /* derived name */
{
    DistanceFieldCache001743b0 *cache = static_cast<DistanceFieldCache001743b0 *>(
        writer->reserve(sizeof(DistanceFieldCache001743b0)));
    hkString::memSet16(cache, &D_14b2060[2], sizeof(*cache) / 16);
    const CollisionCache001785a0::Header header = {6, sizeof(*cache) / 16};
    cache->header = header;
    memset(&cache->unknownA, 0, 6);
    cache->bodyIdA = bodyA->id;
    cache->bodyIdB = bodyB->id;
    cache->childCacheRange.startBlock = HK_NULL;
    cache->childCacheRange.numElements = 0;

    const hknpBodyQuality &qualityA = world->qualityLibrary->qualities[bodyA->qualityId];
    const hknpBodyQuality &qualityB = world->qualityLibrary->qualities[bodyB->qualityId];
    const hknpMaterial &materialA =
        world->materialLibrary->entries.elements[bodyA->materialId.value];
    const hknpMaterial &materialB =
        world->materialLibrary->entries.elements[bodyB->materialId.value];
    const hknpShape *shapeA = bodyA->shape;
    const hknpShape *shapeB = bodyB->shape;
    u32 qualityFlags;
    if (qualityA.priority < qualityB.priority) {
        qualityFlags = qualityA.supportedFlags & qualityB.requestedFlags;
    } else {
        qualityFlags = qualityB.supportedFlags & qualityA.requestedFlags;
    }

    /* A trigger material or a flagged shape on either side asks for flag 4. */
    const u32 materialFlags = materialA.flags | materialB.flags;
    const u16 shapeFlags = shapeA->flags | shapeB->flags;
    if ((materialFlags & hknpMaterial::ENABLE_TRIGGER) | (shapeFlags & 0x10)) {
        qualityFlags |= 4;
    }
    cache->unknownC = u16(qualityFlags);

    /* Both bodies flagged: the distance the collision looks ahead, the
     * larger of the materials' distances scaled by the solver's vector
     * plus both bodies' time of impact distances, clamped to 16 bits. */
    if (bodyA->flags & bodyB->flags & 0x800) {
        const Vec4 timDistances = _mm_add_ps(_mm_set1_ps(float(bodyA->maxContactDistance)),
                                             _mm_set1_ps(float(bodyB->maxContactDistance)));
        const Vec4 maxDistance = _mm_max_ps(
            _mm_set1_ps(materialA.disablingCollisionsBetweenCvxCvxDynamicObjectsDistance.getReal()),
            _mm_set1_ps(
                materialB.disablingCollisionsBetweenCvxCvxDynamicObjectsDistance.getReal()));
        Vec4 distance =
            _mm_add_ps(_mm_mul_ps(maxDistance, world->solverInfo.vector60), timDistances);
        distance = _mm_min_ps(_mm_max_ps(distance, _mm_setzero_ps()), _mm_set1_ps(65535.0f));
        cache->unknownE = u16(_mm_cvtsi128_si32(_mm_cvttps_epi32(distance)));
    }
    writer->advance(sizeof(DistanceFieldCache001743b0));
}
