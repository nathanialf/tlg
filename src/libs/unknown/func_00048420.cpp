/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A vector with x, y and z negated, w kept. derived name. */
static Vec4 negateXyz(const Vec4 &v) /* derived name */
{
    return _mm_xor_ps(
        v, _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), int(0x80000000), int(0x80000000), 0)));
}

void hknpFlippedGetClosestPointsQueryCollector::FUN_00048420(const hknpCollisionResult &hit)
{
    const Vec4 distance = _mm_set1_ps(hit.fraction);
    hknpCollisionResult flipped = hit;
    flipped.normal.quad = negateXyz(hit.normal.quad);
    flipped.position.quad = _mm_add_ps(_mm_mul_ps(distance, hit.normal.quad), hit.position.quad);
    flipped.queryBodyInfo = hit.hitBodyInfo;
    flipped.hitBodyInfo = hit.queryBodyInfo;
    childCollector->addHit(flipped);
    earlyOut = childCollector->earlyOut;
}
