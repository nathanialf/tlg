/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: a rotation turned in place by another before it: the
 * product turn * rotation (FUN_013439c0's body, the lanes in its order),
 * stored back whole with `vmovaps` and the rotation returned. Called and
 * never inlined in the base: defined over its own parameter types,
 * leaf_01403320.cpp's declaration is of another name. */
Float4A *FUN_013cf1d0(Float4A *self, const Float4 &turn) /* derived name */
{
    Float4A &rotation = *self;
    const Float4 &a = turn;
    const Float4A &b = rotation;
    rotation = Float4A(a.x * b.w + a.w * b.x - a.z * b.y + a.y * b.z,
                       a.y * b.w + a.z * b.x + a.w * b.y - a.x * b.z,
                       a.z * b.w - a.y * b.x + a.x * b.y + a.w * b.z,
                       a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z);
    return self;
}
