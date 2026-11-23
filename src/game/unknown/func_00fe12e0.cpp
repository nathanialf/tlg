/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00fe12e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acf730(D_15cb5dd, false);
Name D_5acf734(D_15cb5e6, false);

#include "tlg_game_array01343a80.h"
#include "tlg_math.h"

/* derived names: the record FUN_00fdb6d0 makes two of: an array of three
 * values with its lock at +0x8, 32 cleared bytes from +0x20 and this file's
 * VECTOR_W at +0x40, copied lane by lane from a temporary (two 8-byte
 * loads, four 4-byte stores, COOKBOOK 3300); the first eight bytes are left to the caller. Not traced. */
struct Record013e8590 { /* derived name */
    Record013e8590();

    u8 unknown0[0x8];
    Array01343a80<u32> values; /* +0x8 */
    u32 unknown20[8];          /* +0x20 */
    Float4 unknown40;          /* +0x40: VECTOR_W */
};

/* FUN_013e8590 */
Record013e8590::Record013e8590()
    : unknown20(), unknown40(Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W)))
{
    values.resize(3);
}

#include <algorithm>

/* derived names: the halves of a turn from its cosine, lane by lane over
 * this file's constants: the cosine clamped to [VECTOR_MINUS_ONE,
 * VECTOR_ONE] in each lane, then sqrt((1 - c) / 2) in x, y and z and
 * sqrt((1 + c) / 2) in w, written into `out` (called by FUN_00fdf160,
 * FUN_0116ef40 and FUN_0141f490). The squares are made one vector and
 * kept from going below zero (`vmaxps`); the four roots of its lanes are
 * one vector root after SLP (`vrsqrtps` with its Newton step). */
// NONMATCHING: schedule only (33/44, 234 bytes as the base's): the base
// loads VECTOR_HALF's z lane with x and y before the products (xmm6) and
// makes the three differences before the first insert; here the z lane is
// loaded after the w lane's sum and its difference follows the first
// insert. The products named before the sums give the base's products and
// the w sum first. Lead: the selection DAG's order of the three loads (the
// list scheduler's ties go by node order): which IR order of the lanes'
// loads gives the z load its place without moving the w sum.
void FUN_013e9220(Float4 *out, float cosine) /* derived name */
{
    const Float4Data &low = reinterpret_cast<const Float4Data &>(VECTOR_MINUS_ONE);
    const Float4Data &high = reinterpret_cast<const Float4Data &>(VECTOR_ONE);
    const Float4Data &half = reinterpret_cast<const Float4Data &>(VECTOR_HALF);
    const float x = cosine < low.x ? low.x : std::min(high.x, cosine);
    const float y = cosine < low.y ? low.y : std::min(high.y, cosine);
    const float z = cosine < low.z ? low.z : std::min(high.z, cosine);
    const float w = cosine < low.w ? low.w : std::min(high.w, cosine);
    const float hx = x * 0.5f;
    const float hy = y * 0.5f;
    const float hz = z * 0.5f;
    const float hw = w * 0.5f;
    const Vec4 squares = _mm_max_ps(_mm_setr_ps(half.x - hx, half.y - hy, half.z - hz, half.w + hw),
                                    _mm_setzero_ps());
    out->x = sqrtf(component<0>(squares));
    out->y = sqrtf(component<1>(squares));
    out->z = sqrtf(component<2>(squares));
    out->w = sqrtf(component<3>(squares));
}
