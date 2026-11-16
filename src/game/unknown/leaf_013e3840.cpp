/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtable at 0x16d45d8 (its pointer at
 * 0x16d45f8; stored by FUN_00fbb0f0), over slot 2 of the vtable before it
 * (0x16d4580), FUN_013dfda0, which it calls first. Then two of the
 * 0xa0-byte entries the record at +0x40 of the object at +0x10 holds, by
 * the two indices of the first of four pairs at 0x5acef60 (0x14 bytes each,
 * written by FUN_00f9ab50): the rotation of the second entry, and
 * the rotation of the first with x, y and z negated, passed to
 * FUN_013439c0, which writes the product of two rotations to its first
 * argument (1,442 calls). The product is not used. Its three siblings
 * 0x13e3930, 0x13e3a20 and 0x13e3b10 (slot 2 of the vtables at 0x16d4528,
 * 0x16d4478 and 0x16d43c8) read the second, third and fourth pairs. Class
 * and method unknown. */
struct alignas(16) Rotation013e3840 { /* derived name */

    Rotation013e3840() {}

    Rotation013e3840(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    float x;
    float y;
    float z;
    float w;
};

struct Entry013e3840 { /* derived name */
    u8 unknown0[0x20];
    Rotation013e3840 unknown20; /* +0x20 */
    u8 unknown30[0x70];
};

struct Pose013e3840 { /* derived name */
    Entry013e3840 *unknown0;
};

struct Owner013e3840 { /* derived name */
    u8 unknown0[0x40];
    Pose013e3840 *unknown40;
};

struct Object013e3840 { /* derived name */
    u8 unknown0[0x10];
    Owner013e3840 *unknown10;
};

struct Pair013e3840 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownc;
    int unknown10;
};

extern Pair013e3840 D_5acef60[4]; /* derived: the four pairs of entry indices */

void FUN_013dfda0(Object013e3840 *self); /* derived name */
void FUN_013439c0(Rotation013e3840 *product, const Rotation013e3840 *first,
                  const Rotation013e3840 *second); /* derived name */

// NONMATCHING: list-ilp order: the base forms the third argument's address
// (`lea rdx, [rbp-0x30]`) last, after the inverse's stores, and loads w into
// edx; the build forms it after the copy's index and loads w into eax (a
// union with a vector copy constructor and float pointer parameters measured
// the same; 33/47)
void FUN_013e3840(Object013e3840 *self) /* derived name */
{
    FUN_013dfda0(self);
    const Entry013e3840 *entries = self->unknown10->unknown40->unknown0;
    const Rotation013e3840 &target = entries[D_5acef60[0].unknown8].unknown20;
    const Rotation013e3840 &first = entries[D_5acef60[0].unknown4].unknown20;
    Rotation013e3840 second = target;
    Rotation013e3840 product;
    Rotation013e3840 inverse(-first.x, -first.y, -first.z, first.w);
    FUN_013439c0(&product, &inverse, &second);
}
