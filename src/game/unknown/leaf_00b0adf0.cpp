/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: three slots of the vtable at 0x16b3500 (with FUN_00b0ade0,
 * FUN_00b0ae60 between them): when the reference's owner is set, has its
 * body (+0x28) and its int at +0x4130 (+0x5b24, +0x6280 in the second and
 * third) is non-zero, the object's vector at +0x10 becomes the owner's point
 * (+0x4140, +0x5b30, +0x6290) less the body's position (+0x120), its w taken
 * from the point, and FUN_00b0a9f0 runs on the object. Classes and methods
 * unknown. */
struct Vector00b0adf0 { /* derived name */
    float x, y, z, w;
};

struct Body00b0adf0 { /* derived name */
    u8 unknown0[0x120];
    Vector00b0adf0 position; /* +0x120 */
};

struct Owner00b0adf0 { /* derived name */
    u8 unknown0[0x28];
    Body00b0adf0 *body; /* +0x28 */
    u8 unknown30[0x4130 - 0x30];
    int firstSet; /* +0x4130 */
    u8 unknown4134[0xc];
    Vector00b0adf0 first; /* +0x4140 */
    u8 unknown4150[0x5b24 - 0x4150];
    int secondSet; /* +0x5b24 */
    u8 unknown5b28[0x8];
    Vector00b0adf0 second; /* +0x5b30 */
    u8 unknown5b40[0x6280 - 0x5b40];
    int thirdSet; /* +0x6280 */
    u8 unknown6284[0xc];
    Vector00b0adf0 third; /* +0x6290 */
};

struct Reference00b0adf0 { /* derived name */
    Owner00b0adf0 *owner;
};

struct Object00b0adf0 { /* derived name */
    u8 unknown0[0x10];
    Vector00b0adf0 offset; /* +0x10 */
};

/* a slot of the same vtable (so its unused third argument is still passed) */
void FUN_00b0a9f0(Object00b0adf0 *self, const Reference00b0adf0 *reference,
                  int set); /* derived name */

static inline void place(Object00b0adf0 *self, const Reference00b0adf0 *reference, int set,
                         const Vector00b0adf0 &point) /* derived name */
{
    const Vector00b0adf0 &position = reference->owner->body->position;
    Vector00b0adf0 offset = {point.x - position.x, point.y - position.y, point.z - position.z,
                             point.w};
    self->offset = offset;
    FUN_00b0a9f0(self, reference, set);
}

// NONMATCHING: list-ilp order, the x and y subtractions in the other order (vsubss of +0x120
// first in the base)
void FUN_00b0adf0(Object00b0adf0 *self, const Reference00b0adf0 *reference) /* derived name */
{
    const Owner00b0adf0 *owner = reference->owner;
    if (owner && owner->body && owner->firstSet)
        place(self, reference, owner->firstSet, owner->first);
}

// NONMATCHING: list-ilp order, the x and y subtractions in the other order (vsubss of +0x120
// first in the base)
void FUN_00b0ae70(Object00b0adf0 *self, const Reference00b0adf0 *reference) /* derived name */
{
    const Owner00b0adf0 *owner = reference->owner;
    if (owner && owner->body && owner->secondSet)
        place(self, reference, owner->secondSet, owner->second);
}

// NONMATCHING: list-ilp order, the x and y subtractions in the other order (vsubss of +0x120
// first in the base)
void FUN_00b0b550(Object00b0adf0 *self, const Reference00b0adf0 *reference) /* derived name */
{
    const Owner00b0adf0 *owner = reference->owner;
    if (owner && owner->body && owner->thirdSet)
        place(self, reference, owner->thirdSet, owner->third);
}
