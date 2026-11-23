/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a rotation as a quaternion, x, y, z and w, 16-byte
 * aligned (`vmovaps` stores it whole) */
struct alignas(16) Quaternion { /* derived name */
    float x, y, z, w;
};

/* derived name: the rotation multiplied on the right by another, in place
 * (the Hamilton product), not inlined at its callers (0x615c73, 0xf3f236
 * and on); each lane's terms in FUN_013439c0's order (the second's w, x,
 * y, then z) */
/* OPEN (FINISHING rule 6), checked in round 513D: no caller in the tree declares it yet, so one
 * signature changes no row; a caller written with this signature is measured then */
void FUN_00616e70(Quaternion *q, const Quaternion *r) /* derived name */
{
    const float x = q->x * r->w + q->w * r->x - q->z * r->y + q->y * r->z;
    const float y = q->y * r->w + q->z * r->x + q->w * r->y - q->x * r->z;
    const float z = q->z * r->w - q->y * r->x + q->x * r->y + q->w * r->z;
    const float w = q->w * r->w - q->x * r->x - q->y * r->y - q->z * r->z;
    q->x = x;
    q->y = y;
    q->z = z;
    q->w = w;
}
