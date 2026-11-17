/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5a0 (+0xc0 from the vtable stored at
 * 0x16be490): when its argument has a body (the record at +0x48, its body id
 * at +0x34 not 0x7fffffff, the invalid id), sets that body's transform on the
 * world at +0x38 of the object's record at +0x268 (a null world when that
 * record is null; FUN_0005d6b0): the rotation from the four floats given,
 * normalized, the translation the three floats given, w zero; the last
 * argument 1 when the int given is zero. The classes are not traced. */
struct Body00ea0a90 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Argument00ea0a90 { /* derived name */
    u8 unknown0[0x48];
    Body00ea0a90 *unknown48;
};

struct Record00ea0a90 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea0a90 { /* derived name */
    u8 unknown0[0x268];
    Record00ea0a90 *unknown268;
};

// NONMATCHING: the Newton step's constants: the base forms both addresses with `lea` (0xea0ae2) before the dot product, the single-file module reads them RIP-relative; then loadXYZ_0's zero lane, as leaf_00ea0b80.cpp
void FUN_00ea0a90(Object00ea0a90 *self, Argument00ea0a90 *argument, const float *position,
                  const float *rotation, int unknown) /* derived name */
{
    Body00ea0a90 *body = argument->unknown48;
    if (body == 0) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? self->unknown268->unknown38 : 0;
    const int bodyId = body->unknown34;
    if (bodyId == 0x7fffffff) {
        return;
    }
    hkQuaternion orientation;
    orientation.vec = loadUnaligned4(rotation);
    orientation.normalize();
    hkTransform transform;
    transform.translation = loadXYZ_0(position);
    transform.rotation.FUN_0000bd30(orientation);
    FUN_0005d6b0(world, bodyId, &transform, unknown == 0);
}
