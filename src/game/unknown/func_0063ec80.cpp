/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include <xmmintrin.h>

/* derived names: FUN_0063ec80 tests whether a point is within reach of
 * either of two named points of an object (the names looked up, not
 * interned, kept in a guarded static list 8 bytes above its guard as
 * cookbook 1194, destroyed by the array destructor 0x6422d0). Each point is
 * the position at +0x1c0 of the record FUN_00613440 finds for the name, else
 * the default point D_580f920; the distances are taken by one Newton step of
 * the reciprocal square root estimate (-0.5 and -3 at 0x14d68e4 and
 * 0x14d68e0), zero for a zero length. Within reach, or when the flag at
 * +0x21f8 asks for it once, bit 0x4000 of the flags at +0x2420 is set; when
 * that bit differs from the flags at +0x2424, bit 0x200 of the object's flags
 * follows it. */
struct Vec3063ec80 { /* derived name */
    float x, y, z;

    Vec3063ec80 operator-(const Vec3063ec80 &other) const
    {
        Vec3063ec80 d = {x - other.x, y - other.y, z - other.z};
        return d;
    }

    float length() const /* derived name */
    {
        float lengthSquared = x * x + z * z + y * y;
        float estimate = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(lengthSquared)));
        float length =
            estimate * -0.5f * lengthSquared * (lengthSquared * estimate * estimate - 3.0f);
        return lengthSquared == 0.0f ? 0.0f : length;
    }
};

struct Record00613440 { /* derived name */
    u8 unknown0[0x1c0];
    Vec3063ec80 position; /* +0x1c0, derived name */
};

struct Object063ec80 { /* derived name */
    u8 unknown0[0x24];
    u32 flags24; /* +0x24, derived name */
};

Record00613440 *FUN_00613440(Object063ec80 *object, const Name *name); /* derived name */

extern Vec3063ec80 D_580f920; /* derived name: the point a missing record gives */

struct Owner063ec80 { /* derived name */
    u8 unknown0[0x1e8];
    Object063ec80 *object; /* +0x1e8, derived name */
};

struct Params063ec80 { /* derived name */
    u8 unknown0[0x14];
    float reach; /* +0x14, derived name */
};

struct Self063ec80 { /* derived name */
    u8 unknown0[0x28];
    Owner063ec80 *owner; /* +0x28, derived name */
    u8 unknown30[0x20d8 - 0x30];
    Params063ec80 *params; /* +0x20d8, derived name */
    u8 unknown20e0[0x21f8 - 0x20e0];
    int force; /* +0x21f8, derived name */
    u8 unknown21fc[0x2420 - 0x21fc];
    u32 flags;         /* +0x2420, derived name */
    u32 previousFlags; /* +0x2424, derived name */
};

extern const char D_15ca367[8];
extern const char D_15cb21f[8];

static Vec3063ec80 pointOf(Object063ec80 *object, const Name &name) /* derived name */
{
    Vec3063ec80 point = D_580f920;
    if (Record00613440 *record = FUN_00613440(object, &name))
        point = record->position;
    return point;
}

// NONMATCHING: the base carries each point in integer registers (the default
// loaded as 8 and 4 bytes and split by `shr rcx, 0x20`, the record's three
// fields as three 4-byte loads into ebx, ecx and r12d, moved to xmm by vmovd
// at each subtraction); this build carries them as <2 x float> and float
// (vmovsd, vmovshdup) and spills them, 693 bytes against 687. Written inline
// in the function the build is further off (742 bytes). The tail matches in
// shape but for the flag update, which this build selects with cmovne where
// the base branches.
void FUN_0063ec80(Self063ec80 *self, const Vec3063ec80 *position) /* derived name */
{
    Object063ec80 *object = self->owner->object;
    static Name D_5810b10[] = {Name(D_15ca367, false), Name(D_15cb21f, false)};
    float reach = self->params->reach;
    Vec3063ec80 d0 = pointOf(object, D_5810b10[0]) - *position;
    Vec3063ec80 d1 = pointOf(object, D_5810b10[1]) - *position;
    bool within = true;
    if (self->force != 0) {
        self->force = 0;
    } else {
        float nearest = reach;
        float l0 = d0.length();
        nearest = nearest < l0 ? nearest : l0;
        float l1 = d1.length();
        nearest = nearest < l1 ? nearest : l1;
        within = nearest < self->params->reach;
    }
    if (within)
        self->flags |= 0x4000;
    if ((self->flags ^ self->previousFlags) & 0x4000) {
        if (Object063ec80 *object = self->owner->object) {
            if (within)
                object->flags24 |= 0x200;
            else
                object->flags24 &= ~0x200u;
        }
    }
}
