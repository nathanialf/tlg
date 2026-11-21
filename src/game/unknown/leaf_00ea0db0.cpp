/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5b8 (+0xd8 from the vtable stored at
 * 0x16be490): when its argument has a body (the record at +0x48, its body id
 * at +0x34 not 0x7fffffff, the invalid id), applies the first three floats
 * given times the magnitude of the object's float at +0x39c, w zero, as a
 * linear impulse and the second three floats times it, w zero, as an
 * angular impulse to that body on the world at +0x38 of the object's record
 * at +0x268 (a null world when that record is null), then reads the body's
 * velocities back into the argument's linear (+0x130) and angular (+0x140)
 * velocity, x, y and z with a w of one. The scaled floats are temporaries the
 * vectors are loaded from (x and y stored and read back as one double). The
 * classes are not traced. */
struct Body00ea0db0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Velocity00ea0db0 { /* derived name */
    float x, y, z, w;

    void set(const Vec4 &v)
    {
        x = component<0>(v);
        y = component<1>(v);
        z = component<2>(v);
        w = 1.0f;
    }
};

struct Argument00ea0db0 { /* derived name */
    u8 unknown0[0x48];
    Body00ea0db0 *unknown48;
    u8 unknown50[0x130 - 0x50];
    Velocity00ea0db0 linearVelocity;  /* +0x130 */
    Velocity00ea0db0 angularVelocity; /* +0x140 */
};

/* Three floats as a value aligned to 16 bytes, built as a temporary (the
 * base's slots for them are the frame's last, outside the stack guard's
 * objects: a temporary has no lifetime markers; its three products computed
 * before it is stored; each slot 16-byte aligned) and loaded as a vector
 * with a zero w. derived names. */
struct alignas(16) Float3A_00ea0db0 { /* derived name */

    Float3A_00ea0db0(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    float x;
    float y;
    float z;
};

inline Vec4 loadXYZ_0(const Float3A_00ea0db0 &v) /* derived name */
{
    return loadXYZ_0(&v.x);
}

struct Record00ea0db0 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea0db0 { /* derived name */
    u8 unknown0[0x268];
    Record00ea0db0 *unknown268;
    u8 unknown270[0x39c - 0x270];
    float unknown39c;
};

void FUN_00ea0db0(Object00ea0db0 *self, Argument00ea0db0 *argument, const float *linearImpulse,
                  const float *angularImpulse) /* derived name */
{
    Body00ea0db0 *body = argument->unknown48;
    if (body == 0) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? self->unknown268->unknown38 : 0;
    const int bodyId = body->unknown34;
    if (bodyId == 0x7fffffff) {
        return;
    }
    const float scale = fabsf(self->unknown39c);
    world->FUN_0005e780(
        bodyId, loadXYZ_0(Float3A_00ea0db0(scale * linearImpulse[0], scale * linearImpulse[1],
                                           scale * linearImpulse[2])));
    world->FUN_0005e910(
        bodyId, loadXYZ_0(Float3A_00ea0db0(scale * angularImpulse[0], scale * angularImpulse[1],
                                           scale * angularImpulse[2])));
    Vec4 linearVelocity;
    Vec4 angularVelocity;
    world->FUN_0005dbc0(bodyId, linearVelocity, angularVelocity);
    argument->linearVelocity.set(linearVelocity);
    argument->angularVelocity.set(angularVelocity);
}
