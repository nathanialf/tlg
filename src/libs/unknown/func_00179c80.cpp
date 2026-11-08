/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The convex pair's cache creator (derived reading): two shapes of type 3
 * go to the distance field's creator, the one of the larger convex radius
 * second; otherwise a cache of type 2 as the distance field's creator
 * fills its header; the qualities and materials are found before the
 * block is reserved (their loads ahead of the writer's call). */
void FUN_00179c80(const hknpWorld *world, const hknpBody *bodyA, const hknpBody *bodyB,
                  hkBlockStreamWriter *writer) /* derived name */
{
    if (bodyA->shape->unknownVirtual5() == 3 && bodyB->shape->unknownVirtual5() == 3) {
        if (bodyA->shape->convexRadius >= bodyB->shape->convexRadius) {
            FUN_001743b0(world, bodyB, bodyA, writer);
        } else {
            FUN_001743b0(world, bodyA, bodyB, writer);
        }
        return;
    }

    const hknpBodyQuality &qualityA = world->qualityLibrary->qualities[bodyA->qualityId];
    const hknpBodyQuality &qualityB = world->qualityLibrary->qualities[bodyB->qualityId];
    const hknpMaterial &materialA =
        world->materialLibrary->entries.elements[bodyA->materialId.value];
    const hknpMaterial &materialB =
        world->materialLibrary->entries.elements[bodyB->materialId.value];
    ConvexConvexCache00179c80 *cache = static_cast<ConvexConvexCache00179c80 *>(
        writer->reserve(sizeof(ConvexConvexCache00179c80)));
    hkString::memSet16(cache, &D_14b2060[2], sizeof(*cache) / 16);
    const CollisionCache001785a0::Header header = {2, sizeof(*cache) / 16};
    cache->header = header;
    cache->unknownA = 0;
    cache->unknownC = 0;
    cache->unknownE = 0;
    cache->unknown10 = 0;
    cache->unknown12 = 0;
    cache->unknown14 = 0x41;
    cache->unknown16 = 0;
    cache->unknown18 = 0;
    cache->bodyIdA = bodyA->id;
    cache->bodyIdB = bodyB->id;

    const hknpShape *shapeA = bodyA->shape;
    const hknpShape *shapeB = bodyB->shape;
    u32 qualityFlags;
    if (qualityA.priority < qualityB.priority) {
        qualityFlags = qualityA.supportedFlags & qualityB.requestedFlags;
    } else {
        qualityFlags = qualityB.supportedFlags & qualityA.requestedFlags;
    }

    const u32 materialFlags = materialA.flags | materialB.flags;
    const u16 shapeFlags = shapeA->flags | shapeB->flags;
    if ((materialFlags & hknpMaterial::ENABLE_TRIGGER) | (shapeFlags & 0x10)) {
        qualityFlags |= 4;
    }
    cache->unknownC = u16(qualityFlags);

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
    writer->advance(sizeof(ConvexConvexCache00179c80));
}
