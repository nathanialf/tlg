/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the record's contact points in the world, at most four,
 * and their distances: each entry's point on the side of the motion that
 * is not the static one, rotated by that motion and turned about the
 * direction (its sign by the side), the first one the reference on the
 * direction's plane and the others brought onto the plane through it along
 * the packed normal (the direction when the normal is zero), then offset by
 * the motion's centre of mass; the distances the entries' values B scaled
 * by the info and negated, the smallest kept. */
// NONMATCHING: 2 of 141 by position (630 bytes against 615); the orientation is read into a
// local before the loop as the base's is (its load and w*w - 1/2 before the loop, 0x2b490 to
// 0x2b4cb, where a read in the loop stays in it: the output's stores may alias the motion).
// Left: (1) the side's test: the base sets the side once (`cmp [rcx+0x2c], 0; setne; movzx`,
// the branch on the same flags) and keeps rbx for the count, here the side is tested twice;
// (2) the first point's reference (the direction times its w, 0x2b548): in the loop's first
// block in the base, hoisted by LICM and spilled here; the base's direction is a register in
// the loop (xmm2), so a reference read back from the output (round 79A's lead) is not it.
// NOTES Round 79A and Round 80A.
void FUN_0002b3b0(const Info0002b180 *info, Pair08Owner *self, const hknpMotion *motionA,
                  const hknpMotion *motionB, Output0002b3b0 *out)
{
    const hknpMotion *motions[2] = {motionA, motionB};
    Vec4 sign = D_14b2060[3];
    const int side = motionB->solverId != 0;
    if (side) {
        sign = _mm_sub_ps(_mm_setzero_ps(), sign);
    }
    const hknpMotion *motion = motions[side];
    const hkQuaternion orientation = motion->orientation;
    const Vec4 distanceScale = _mm_mul_ps(_mm_set1_ps(info->value130), info->vector40);
    const int count = self->count < 4 ? self->count : 4;
    const Vec4 direction = self->direction;
    const Vec4 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    const __m128i packed = _mm_loadl_epi64(reinterpret_cast<const __m128i *>(self->unknown30));
    Vec4 normal =
        _mm_mul_ps(_mm_cvtepi32_ps(_mm_add_epi32(_mm_unpacklo_epi16(_mm_setzero_si128(), packed),
                                                 _mm_castps_si128(D_14b41d0))),
                   D_14b2060[49]);
    out->numEntries = count;
    out->vector10 = direction;
    if (_mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmpeq_ps(normal, _mm_setzero_ps()), xyz)),
                        _mm_castps_si128(xyz))) {
        normal = direction;
    }
    Vec4 minDistance = D_14b2060[33];
    const Pair08Entry *entry = reinterpret_cast<const Pair08Entry *>(self + 1);
    Vec4 reference = _mm_setzero_ps();
    for (int i = 0; i < count; i++) {
        const Vec4 &local = (&entry[i].vectorA)[side];
        const Vec4 rotated = rotatedDir(orientation, local);
        Vec4 point = _mm_mul_ps(sign, cross3(direction, rotated));
        if (i == 0) {
            reference = _mm_add_ps(_mm_mul_ps(direction, _mm_shuffle_ps(direction, direction,
                                                                        _MM_SHUFFLE(3, 3, 3, 3))),
                                   point);
            point = reference;
        } else {
            const Vec4 denominator = _mm_dp_ps(direction, normal, 0x7f);
            const Vec4 safeDenominator =
                _mm_cvtss_f32(hkMath::quadFabs(_mm_sub_ps(denominator, D_14b2060[2]))) <
                        _mm_cvtss_f32(D_14b2060[35])
                    ? _mm_set1_ps(1.0f)
                    : denominator;
            const Vec4 r = _mm_rcp_ps(safeDenominator);
            const Vec4 inverse =
                _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(safeDenominator, r)));
            const Vec4 along = _mm_dp_ps(_mm_sub_ps(reference, point), normal, 0x7f);
            point = _mm_add_ps(point, _mm_mul_ps(direction, _mm_mul_ps(along, inverse)));
        }
        out->vectors[i] = _mm_add_ps(point, motion->centerOfMass);
        const Vec4 distance =
            _mm_xor_ps(_mm_mul_ps(distanceScale, _mm_shuffle_ps(entry[i].vectorB, entry[i].vectorB,
                                                                _MM_SHUFFLE(3, 3, 3, 3))),
                       _mm_set1_ps(-0.0f));
        reinterpret_cast<float *>(&out->distances)[i] = _mm_cvtss_f32(distance);
        minDistance = _mm_min_ps(minDistance, distance);
    }
    out->value4 = _mm_cvtss_f32(minDistance);
}
