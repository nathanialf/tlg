/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5b0 (+0xd0 from the vtable stored at
 * 0x16be490): when its argument has a body (the record at +0x48, its body id
 * at +0x34 not 0x7fffffff, the invalid id), applies the three floats given,
 * w zero, as an impulse at the point the second three floats give, w zero,
 * to that body on the world at +0x38 of the object's record at +0x268 (a
 * null world when that record is null), then reads the body's velocities
 * back into the argument's linear (+0x130) and angular (+0x140) velocity,
 * x, y and z with a w of one. The classes are not traced. */
struct Body00ea0c90 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Velocity00ea0c90 { /* derived name */
    float x, y, z, w;

    void set(const Vec4 &v)
    {
        x = component<0>(v);
        y = component<1>(v);
        z = component<2>(v);
        w = 1.0f;
    }
};

struct Argument00ea0c90 { /* derived name */
    u8 unknown0[0x48];
    Body00ea0c90 *unknown48;
    u8 unknown50[0x130 - 0x50];
    Velocity00ea0c90 linearVelocity;  /* +0x130 */
    Velocity00ea0c90 angularVelocity; /* +0x140 */
};

struct Record00ea0c90 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea0c90 { /* derived name */
    u8 unknown0[0x268];
    Record00ea0c90 *unknown268;
};

void FUN_00ea0c90(Object00ea0c90 *self, Argument00ea0c90 *argument, const float *impulse,
                  const float *position) /* derived name */
{
    Body00ea0c90 *body = argument->unknown48;
    if (body == 0) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? self->unknown268->unknown38 : 0;
    const int bodyId = body->unknown34;
    if (bodyId == 0x7fffffff) {
        return;
    }
    world->FUN_0005eb00(bodyId, loadXYZ_0(impulse), loadXYZ_0(position));
    Vec4 linearVelocity;
    Vec4 angularVelocity;
    world->FUN_0005dbc0(bodyId, linearVelocity, angularVelocity);
    argument->linearVelocity.set(linearVelocity);
    argument->angularVelocity.set(angularVelocity);
}
