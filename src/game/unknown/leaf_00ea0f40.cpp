/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5c0 (+0xe0 from the vtable stored at
 * 0x16be490): as 0xea0c90, the impulse scaled by the magnitude of the
 * object's float at +0x39c first: when its argument has a body (the record
 * at +0x48, its body id at +0x34 not 0x7fffffff, the invalid id), applies
 * the three floats given times that magnitude, w zero, as an impulse at the
 * point the second three floats give, w zero, to that body on the world at
 * +0x38 of the object's record at +0x268 (a null world when that record is
 * null), then reads the body's velocities back into the argument's linear
 * (+0x130) and angular (+0x140) velocity, x, y and z with a w of one. The
 * scaled floats are a temporary the vector is loaded from (x and y stored
 * and read back as one double). The classes are not traced. */
struct Body00ea0f40 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Velocity00ea0f40 { /* derived name */
    float x, y, z, w;

    void set(const Vec4 &v)
    {
        x = component<0>(v);
        y = component<1>(v);
        z = component<2>(v);
        w = 1.0f;
    }
};

struct Argument00ea0f40 { /* derived name */
    u8 unknown0[0x48];
    Body00ea0f40 *unknown48;
    u8 unknown50[0x130 - 0x50];
    Velocity00ea0f40 linearVelocity;  /* +0x130 */
    Velocity00ea0f40 angularVelocity; /* +0x140 */
};

/* Three floats as a value aligned to 16 bytes, built as a temporary (the
 * base's slot for it is the frame's last, outside the stack guard's
 * objects: a temporary has no lifetime markers; its three products computed
 * before it is stored; the slot 16-byte aligned, as leaf_00ea0db0.cpp's)
 * and loaded as a vector with a zero w. derived names. */
struct alignas(16) Float3_00ea0f40 { /* derived name */

    Float3_00ea0f40(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    float x;
    float y;
    float z;
};

inline Vec4 loadXYZ_0(const Float3_00ea0f40 &v) /* derived name */
{
    return loadXYZ_0(&v.x);
}

struct Record00ea0f40 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea0f40 { /* derived name */
    u8 unknown0[0x268];
    Record00ea0f40 *unknown268;
    u8 unknown270[0x39c - 0x270];
    float unknown39c;
};

void FUN_00ea0f40(Object00ea0f40 *self, Argument00ea0f40 *argument, const float *impulse,
                  const float *position) /* derived name */
{
    Body00ea0f40 *body = argument->unknown48;
    if (body == 0) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? self->unknown268->unknown38 : 0;
    const int bodyId = body->unknown34;
    if (bodyId == 0x7fffffff) {
        return;
    }
    const float scale = fabsf(self->unknown39c);
    world->FUN_0005eb00(
        bodyId,
        loadXYZ_0(Float3_00ea0f40(scale * impulse[0], scale * impulse[1], scale * impulse[2])),
        loadXYZ_0(position));
    Vec4 linearVelocity;
    Vec4 angularVelocity;
    world->FUN_0005dbc0(bodyId, linearVelocity, angularVelocity);
    argument->linearVelocity.set(linearVelocity);
    argument->angularVelocity.set(angularVelocity);
}
