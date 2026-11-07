/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <immintrin.h>

#include "tlg_lib_unknown.h"

// NONMATCHING: 116 of 120, one pair in the join after the second tolerance:
// the base loads the cache after the tolerances' minimum (`vpshufd; vminps;
// spill; mov r14, [r12+0xa8]`), this compile before it. Measured with the
// debug llc (-debug-only=pre-RA-sched): at step 13 of that block both the
// minimum (VMINPSrr) and the cache's load (MOV64rm, ORD 69) are available
// and list-ilp takes the minimum first, so the load ends above it. The
// statements' order, the tolerances' and the overlap test's places, and the
// flags read in each branch all compile the same (NOTES, round 74B).
void Modifier16a5020::FUN_001620c0(CommandOwner00171180 *context,
                                   const ModifierSharedData *sharedData, const hknpCdBody *cdBodyA,
                                   const hknpCdBody *cdBodyB, hknpManifold *manifold) const
{
    hknpManifoldCollisionCache *cache;
    Vec4 distance;
    if ((cdBodyA->body->flags | cdBodyB->body->flags) & hknpBody::RAISE_TRIGGER_EVENTS) {
        const Vec4 toleranceA = _mm_set1_ps(cdBodyA->material->triggerManifoldTolerance.getReal());
        const Vec4 toleranceB = _mm_set1_ps(cdBodyB->material->triggerManifoldTolerance.getReal());
        const Vec4 tolerance = _mm_min_ps(toleranceA, toleranceB);
        const Vec4 minDistance = _mm_broadcast_ss(&manifold->minDistance);
        if (!(_mm_cvtss_f32(minDistance) >= 0.0f)) {
            /* The shapes overlap: the trigger entered, its event posted
             * once. */
            cache = manifold->collisionCache;
            const u16 flags = cache->flags22;
            cache->flags22 = flags | 0x10;
            if (!(flags & 8)) {
                ManifoldEvent169b1a0 event(cdBodyA->body->byte7f, cdBodyA->body->id,
                                           cdBodyB->body->byte7f, cdBodyB->body->id, 1,
                                           ManifoldEvent169b1a0::STATUS_CREATED, cdBodyA->shapeKey,
                                           cdBodyB->shapeKey);
                context->dispatcher->exec(event);
                cache->flags22 |= 8;
            }
        } else {
            cache = manifold->collisionCache;
            const u16 flags = cache->flags22;
            cache->flags22 = flags & ~0x10;
        }
        const __m128i bits = _mm_castps_si128(minDistance);
        distance =
            _mm_add_ps(tolerance, _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1)));
    } else {
        distance = D_14b2060[33];
        cache = manifold->collisionCache;
    }
    distance = _mm_mul_ps(distance, sharedData->solverInfo->vector60);
    distance = _mm_min_ps(_mm_max_ps(distance, _mm_setzero_ps()), _mm_set1_ps(65535.0f));
    cache->unknownE = u16(_mm_cvtsi128_si32(_mm_cvttps_epi32(distance)));
    manifold->byte90 = 1;
}
