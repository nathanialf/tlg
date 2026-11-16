/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: a joint of 32 bytes, its position and its rotation (a
 * quaternion, 16-byte aligned: FUN_013cf1d0 stores it with `vmovaps`) */
struct Joint01403320 { /* derived name */
    Float4 position;   /* +0x0 */
    Float4A rotation;  /* +0x10 */
};

void FUN_01353470(Float4Data &axis,
                  const Float4A &rotation); /* derived name: the rotation's axis */
void FUN_01401f60(Float4 &out, const void *object, const Float4 &value); /* derived name */
Float4A &FUN_013cf1d0(Float4A &rotation,
                      const Float4 &turn); /* derived name: the product, in place */

static inline Float4Data axisOf(const Float4A &rotation) /* derived name */
{
    Float4Data axis;
    FUN_01353470(axis, rotation);
    return axis;
}

/* derived name: turns a joint toward a point: the rotation's axis, the
 * direction to the point (its w the point's) made unit length where it is
 * not shorter than 1e-5, the turn between them, the rotation multiplied by
 * it. One of 18 byte-identical functions (0x1403320, 0x1405040, ...
 * 0x1495200), each called by its neighbours. */
// NONMATCHING: the axis's copy into forward: the base reads it as two qwords and stores four dwords
// (`mov rax, [rbp-0x40]; mov [rbp-0x50], eax; shr rax, 0x20`), an integer-class coerced copy; the
// build moves it as one vector (`vmovups`); the frame (0x38, the axis's slot reused for the
// direction) is the base's since the axis is a temporary; 19/84
void FUN_01403320(Joint01403320 *joints, unsigned index, const Float4 &target)
{
    Joint01403320 &joint = joints[index];
    Float4 forward(axisOf(joint.rotation));
    Float4 direction(target.x - joint.position.x, target.y - joint.position.y,
                     target.z - joint.position.z, target.w);
    float length =
        sqrtf(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
    if (length >= 1e-5f) {
        float scale = 1.0f / length;
        direction.x = scale * direction.x;
        direction.y = scale * direction.y;
        direction.z = scale * direction.z;
        Float4 turn;
        FUN_01401f60(turn, &forward, direction);
        FUN_013cf1d0(joint.rotation, turn);
    }
}
