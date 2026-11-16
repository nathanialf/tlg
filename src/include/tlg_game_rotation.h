/* src/include/tlg_game_rotation.h: a rotation held in a four-lane vector
 * (x, y, z, then w) and the steps the game region applies to one in place
 * (docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_ROTATION_H
#define TLG_GAME_ROTATION_H

#include "tlg_math.h"
#include "tlg_simd.h"
#include "tlg_game_vector.h"

/* derived name: the rotation turned to the half where w is not negative,
 * lane by lane against the including unit's VECTOR_ZERO: the lanes read
 * once into a plain copy (one unaligned vector load, w its lane 3 by
 * `vpermilps 0xe7`), each lane's test before the negation (the three zero
 * lanes loaded before the negation's `vxorps` is stored, the first folded
 * into `vucomiss`), the negation in memory, and each lane picked from it
 * or from the rotation (an address picked, then an integer load), all four
 * read before the four stores (FUN_013d4610 and its copies) */
inline void makeWPositive(Vec4 &q) /* derived name */
{
    const Float4Data v = {lane(q, 0), lane(q, 1), lane(q, 2), lane(q, 3)};
    const float w = v.w;
    bool below[4];
    for (int k = 0; k < 4; ++k)
        below[k] = w < lane(VECTOR_ZERO.v, k);
    Vec4 neg;
    for (int k = 0; k < 4; ++k)
        lane(neg, k) = -(&v.x)[k];
    Vec4 r;
    for (int k = 0; k < 4; ++k)
        lane(r, k) = below[k] ? lane(neg, k) : lane(q, k);
    for (int k = 0; k < 4; ++k)
        lane(q, k) = lane(r, k);
}

/* derived name: a vector set lane by lane from a constant copied whole as
 * four plain floats (two 64-bit loads, then four 32-bit stores: the copy
 * reaches the lanes as integers) */
inline void setLanes(Vec4 &dst, const Vector4 &src) /* derived name */
{
    const Float4Data value = reinterpret_cast<const Float4Data &>(src);
    lane(dst, 0) = value.x;
    lane(dst, 1) = value.y;
    lane(dst, 2) = value.z;
    lane(dst, 3) = value.w;
}

#endif
