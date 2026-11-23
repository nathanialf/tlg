/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_matrix01343890.h"

/* derived names: the rotation matrix of a quaternion, each entry divided by
 * the quaternion's squared length, the position as the fourth row.
 * NONMATCHING: 6/64 (289 bytes, base 292): the arithmetic is the base's
 * (the squared length (yy + xx) + (zz + ww), the diagonals xx - yy - zz + ww
 * and the doubled sums), but the base loads 1.0 and forms -xx first and
 * computes the six values of the first two rows before any store, where
 * here each row's values are computed between the stores (written as
 * members, then as Float4A rows: the same); not traced. */
void FUN_01343890(Matrix01343890 *out, const Float4A &q, const Float4A &position) /* derived name */
{
    float xx = q.x * q.x;
    float yy = q.y * q.y;
    float zz = q.z * q.z;
    float ww = q.w * q.w;
    float xy = q.x * q.y;
    float xz = q.x * q.z;
    float yz = q.y * q.z;
    float wx = q.w * q.x;
    float wy = q.w * q.y;
    float wz = q.w * q.z;
    float inv = 1.0f / (xx + yy + zz + ww);
    out->rows[0] =
        Float4A((xx - yy - zz + ww) * inv, 2.0f * (xy + wz) * inv, 2.0f * (xz - wy) * inv, 0.0f);
    out->rows[1] =
        Float4A(2.0f * (xy - wz) * inv, (yy - xx - zz + ww) * inv, 2.0f * (yz + wx) * inv, 0.0f);
    out->rows[2] =
        Float4A(2.0f * (xz + wy) * inv, 2.0f * (yz - wx) * inv, (zz - xx - yy + ww) * inv, 0.0f);
    out->rows[3] = position;
}
