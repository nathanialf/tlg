/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: a point turned by a rotation (the rotation's matrix, each
 * entry divided by its squared length, as FUN_01343890 builds it), written
 * to its first argument as a whole point whose w is the point's (no value
 * returned: rax is not set). Called and never inlined in the base: defined
 * over its own parameter types, tlg_game_object00774560.h's declaration is
 * of another name. */
// NONMATCHING: 6/66 (65 instructions, base 66): the diagonals are the base's shared terms
// (ww - zz and xx - yy for the first two, -xx - yy then zz + ww for the third, zz + ww also
// in the squared length), the doubled sums (A + p * d) + A as the base; the schedule differs
// from the first product on (the base: zx, wx, yx, wy, zy, wz), FUN_01343890's open class
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 6 rowed callers where the base calls it (round 513D: cause not found;
 * not its address range, its callers' count, its cost or its unit: a single block, cost 195 to
 * 235 under the link's threshold of 262 with its bonuses, and with it outside the module every
 * row holds) */
void FUN_01343bb0(Float4A *out, const Float4A &point, const Float4A &q) /* derived name */
{
    float xx = q.x * q.x;
    float yy = q.y * q.y;
    float zz = q.z * q.z;
    float ww = q.w * q.w;
    float xz = q.x * q.z;
    float wx = q.w * q.x;
    float xy = q.x * q.y;
    float wy = q.w * q.y;
    float yz = q.y * q.z;
    float wz = q.w * q.z;
    float wwzz = ww - zz;
    float xxyy = xx - yy;
    float zzww = zz + ww;
    float inv = 1.0f / (xx + yy + zzww);
    *out = Float4A(
        ((wwzz + xxyy) * point.x + 2.0f * (xy - wz) * point.y + 2.0f * (xz + wy) * point.z) * inv,
        (2.0f * (xy + wz) * point.x + (wwzz - xxyy) * point.y + 2.0f * (yz - wx) * point.z) * inv,
        (2.0f * (xz - wy) * point.x + 2.0f * (yz + wx) * point.y + (zzww - xx - yy) * point.z) *
            inv,
        point.w);
}
