/* src/include/tlg_game_aim010c25d0.h: the object that turns two bones of a
 * pose toward points before them (FUN_010c25d0 the first, FUN_010c2a50 the
 * second; FUN_012ce440 is FUN_010c25d0 in another unit, over that unit's
 * VECTOR_ZERO and VECTOR_W). Every name here is derived; the class's other
 * fields are not traced. */
#ifndef TLG_GAME_AIM010C25D0_H
#define TLG_GAME_AIM010C25D0_H

#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_simd.h"
#include "tlg_types.h"
#include "tlg_game_rotation.h"
#include "tlg_game_speed.h"
#include "tlg_game_vector.h"

/* derived names: a bone's position and rotation (FUN_010c1ce0 copies the
 * first, FUN_010c25d0 the second, FUN_010c2a50 the third, each with two
 * aligned vector moves) */
struct Bone010c25d0 { /* derived name */
    Float4A position; /* +0x0 */
    Float4A rotation; /* +0x10: a quaternion */

    /* derived name: the point an offset in the bone's frame reaches */
    Float4A pointAt(float x, float y, float z);
};

struct Pose010c25d0 { /* derived name */
    Bone010c25d0 bones[3];
};

/* derived name: four rows, as FUN_00f52470 writes them and FUN_013cee80
 * reads its diagonal (+0x0, +0x14, +0x28) */
struct Matrix010c25d0 { /* derived name */
    Vec4 rows[4];

    /* derived name: the matrix's rotation as a quaternion, w not negative */
    void getRotation(Float4A &rotation) const;
};

/* derived names: one bone's limits, three of them from +0xd8 of the
 * settings (the table at +0x180 follows them) */
struct Limit010c25d0 { /* derived name */
    float reach;       /* +0x0: the forward offset's scale (back when not positive) */
    float floor;       /* +0x4: the least of the bone's lift */
    u8 unknown8[0x38 - 0x8];
};

struct Settings010c25d0 { /* derived name */
    u8 unknown0[0xd8];
    Limit010c25d0 limits[3]; /* +0xd8 */
    u8 unknown180[0x264 - 0x180];
    float weights[3]; /* +0x264 */
};

/* derived names: the offsets one bone is aimed by, at +0xe0 and +0x140 of
 * the object */
struct Aim010c25d0 {  /* derived name */
    Float4A base;     /* +0x0 */
    Float4A forward;  /* +0x10 */
    Float4A backward; /* +0x20 */
    Float4A up;       /* +0x30 */
    Float4A down;     /* +0x40 */
    float angle;      /* +0x50: degrees about the bone's x axis */
};

/* derived names: a point rotated in place (the result its argument) */
const Float4 *FUN_0134b990(void *field, const Float4A *point); /* derived name */
/* derived name: a rotation looking from a point toward another, its up
 * toward a third, as four rows; 0 when the points are too close */
int FUN_00f52470(Matrix010c25d0 *out, const Float4A *upPoint, int axes, float fromX, float fromY,
                 float fromZ, float toX, float toY, float toZ); /* derived name */
/* derived name: a rotation's quaternion from its matrix */
void FUN_013cee80(Float4A *rotation, const Matrix010c25d0 *matrix); /* derived name */
/* derived name: a rotation turned about one axis by an angle given as its
 * sine and cosine */
void FUN_00fbd3b0(Float4A *rotation, float sine, float cosine, int axis); /* derived name */

inline void Matrix010c25d0::getRotation(Float4A &rotation) const
{
    Float4A q;
    FUN_013cee80(&q, this);
    makeWPositive(q);
    rotation = q;
}

inline Float4A Bone010c25d0::pointAt(float x, float y, float z)
{
    Float4A offset(x, y, z, 0.0f);
    FUN_0134b990(&rotation, &offset);
    return Float4A(offset.x + position.x, offset.y + position.y, offset.z + position.z, 0.0f);
}

class Aimer010c25d0 /* derived name */
{
  public:
    void aimFirst(); /* derived name */

    u8 unknown0[0x10];
    Settings010c25d0 *settings; /* +0x10 */
    u8 unknown18[0x30 - 0x18];
    Pose010c25d0 *pose; /* +0x30 */
    u8 unknown38[0x48 - 0x38];
    Pose010c25d0 *source; /* +0x48 */
    u8 unknown50[0x64 - 0x50];
    int index; /* +0x64 */
    u8 unknown68[0xc0 - 0x68];
    float unknownc0; /* +0xc0 */
    float unknownc4; /* +0xc4 */
    float lifts[2];  /* +0xc8 */
    u8 unknownd0[0xe0 - 0xd0];
    Aim010c25d0 aims[2]; /* +0xe0 */
    float unknown1a0;    /* +0x1a0 */
    float unknown1a4;    /* +0x1a4 */
};

#endif
