/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a rotation as a quaternion, x, y, z and w, 16-byte
 * aligned (`vmovaps` stores it whole) */
struct alignas(16) Quaternion { /* derived name */
    float x, y, z, w;
};

/* derived name: the rotation multiplied on the right by another, in place
 * (the Hamilton product), not inlined at its callers (0x615c73, 0xf3f236
 * and on) */
// NONMATCHING: instruction order only (181 bytes, base 182): every load, register and expression
// tree as the base's (the x component's first uses give the loads' ranks: x, rw, w, rx, z, ry, y, rz),
// the build schedules y's w * ry before y * rw (`vmulss xmm10, xmm6, xmm4` at +0x24, the base's
// `vmulss xmm9, xmm2, xmm0`)
void FUN_00616e70(Quaternion *q, const Quaternion *r) /* derived name */
{
    const float x = q->x * r->w + q->w * r->x - q->z * r->y + q->y * r->z;
    const float y = q->y * r->w + q->w * r->y + q->z * r->x - q->x * r->z;
    const float z = q->z * r->w + q->w * r->z + q->x * r->y - q->y * r->x;
    const float w = q->w * r->w - q->x * r->x - q->y * r->y - q->z * r->z;
    q->x = x;
    q->y = y;
    q->z = z;
    q->w = w;
}
