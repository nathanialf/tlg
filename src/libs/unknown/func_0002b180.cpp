/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The extra bytes each type of record carries after its entries (derived
 * name), the table FUN_0002af30's file holds too. */
static const int D_14b8690[5] = {0, 0, 0, 144, 144};

/* derived name: a surface velocity applied to the record: the linear one
 * and the angular one along the direction into the target, scaled by its
 * half and the info's vector at +0x20; for a record of type 3 or 4, the
 * linear one along two unit vectors perpendicular to the direction and the
 * angular one along it taken from the vector after the tail's header, and
 * added into the w of the extra rows scaled by the info's +0x120 too. */
void FUN_0002b180(const Info0002b180 *info, Pair08Owner *self, const Vec4 &a, const Vec4 &b)
{
    const Vec4 direction = self->direction;
    const Vec4 angular = _mm_dp_ps(direction, b, 0x7f);
    Pair08Target *target = self->target;
    if (target) {
        const Vec4 velocity = _mm_blend_ps(a, angular, 8);
        const Vec4 scale = _mm_mul_ps(_mm_set1_ps(target->scale.getReal()), info->vector20);
        target->sum = _mm_add_ps(target->sum, _mm_mul_ps(velocity, scale));
    }
    if (self->type >= 3) {
        /* Two unit vectors perpendicular to the direction, as Havok's
         * hkVector4Util::calculatePerpendicularNormalizedVectors is: the
         * perpendicular of perpendicular3 and its cross product with the
         * direction, both scaled by the perpendicular's inverse length. */
        const Vec4 xyz = setXYZ_0(direction);
        const Vec4 yx00 = _mm_shuffle_ps(xyz, xyz, _MM_SHUFFLE(3, 3, 0, 1));
        const Vec4 z0x0 = _mm_shuffle_ps(xyz, xyz, _MM_SHUFFLE(3, 0, 3, 2));
        const Vec4 flipX = _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), 0, 0, 0));
        const Vec4 lengthA = _mm_dp_ps(direction, direction, 0x3f);
        const Vec4 lengthB = _mm_dp_ps(z0x0, z0x0, 0xff);
        const Vec4 perpendicular = _mm_blendv_ps(_mm_xor_ps(yx00, flipX), _mm_xor_ps(z0x0, flipX),
                                                 _mm_cmplt_ps(lengthA, lengthB));
        const Vec4 lengthSquared = _mm_max_ps(lengthA, lengthB);
        const Vec4 e = _mm_rsqrt_ps(lengthSquared);
        const Vec4 invLength = _mm_mul_ps(
            _mm_mul_ps(e, _mm_load_ps(D_14b4360)),
            _mm_sub_ps(_mm_load_ps(D_14b4390), _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
        const Vec4 tangentB = _mm_mul_ps(cross3(direction, perpendicular), invLength);
        const Vec4 tangentA = _mm_mul_ps(perpendicular, invLength);
        const Vec4 alongB = _mm_dp_ps(a, tangentB, 0x7f);
        const Vec4 alongA = _mm_dp_ps(a, tangentA, 0x7f);

        const int offset =
            sizeof(Pair08Owner) + self->count * sizeof(Pair08Entry) + D_14b8690[self->type];
        Pair08Tail *tail = reinterpret_cast<Pair08Tail *>(reinterpret_cast<char *>(self) + offset);
        Vec4 &rhs = *reinterpret_cast<Vec4 *>(reinterpret_cast<char *>(tail) +
                                              (tail->hasFlags() ? sizeof(Vec4) : 0));
        const Vec4 minusOne = negateScalar(D_14b2060[3]);
        const Vec4 value = rhs;
        const Vec4 x = _mm_add_ps(broadcast<0>(value), _mm_mul_ps(alongA, minusOne));
        const Vec4 y = _mm_add_ps(broadcast<1>(value), _mm_mul_ps(alongB, minusOne));
        const Vec4 z = _mm_add_ps(broadcast<2>(value), _mm_mul_ps(angular, minusOne));
        rhs = _mm_blend_ps(_mm_blend_ps(_mm_move_ss(value, x), y, 2), z, 4);

        if (target) {
            const unsigned long extraOffset =
                sizeof(Pair08Owner) + self->count * sizeof(Pair08Entry);
            Pair08Extra *extra =
                reinterpret_cast<Pair08Extra *>(reinterpret_cast<char *>(self) + extraOffset);
            const Vec4 factor = _mm_mul_ps(_mm_mul_ps(info->vector120, info->vector20),
                                           _mm_set1_ps(target->scale.getReal()));
            const Vec4 row0 = extra->rows[0].vectorA;
            const Vec4 row1 = extra->rows[1].vectorA;
            const Vec4 row2 = extra->rows[2].vectorB;
            extra->rows[0].vectorA =
                _mm_blend_ps(row0, _mm_add_ps(broadcast<3>(row0), _mm_mul_ps(alongA, factor)), 8);
            extra->rows[1].vectorA =
                _mm_blend_ps(row1, _mm_add_ps(broadcast<3>(row1), _mm_mul_ps(alongB, factor)), 8);
            extra->rows[2].vectorB =
                _mm_blend_ps(row2, _mm_add_ps(broadcast<3>(row2), _mm_mul_ps(angular, factor)), 8);
        }
    }
}
