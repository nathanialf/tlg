/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_math.h"

static const float EPSILON = 1e-5f; /* derived name: as leaf_00206a90.cpp's */

/* derived names: the body at +0x28: its position at +0x120 and its rotation
 * at +0x140 */
struct Body0042da30 { /* derived name */
    u8 unknown0[0x120];
    Float4A position; /* +0x120 */
    u8 unknown130[0x10];
    Float4A rotation; /* +0x140 */
};

/* derived names: the base class of the vtables at 0x16a8178, 0x16a9990,
 * 0x16aa3c8, 0x16aa4d0, 0x16aa5d8 and 0x16aa6e0 (their slot 17) as the slot
 * sees it: the body, the position and heading taken from it and the ones
 * of the step before */
struct Object0042da30 { /* derived name */
    u8 unknown0[0x28];
    Body0042da30 *body; /* +0x28 */
    u8 unknown30[0x20];
    Float4A position;         /* +0x50 */
    Float4A previousPosition; /* +0x60 */
    Float4A heading;          /* +0x70 */
    Float4A previousHeading;  /* +0x80 */
};

/* derived names: slot 17 of the six vtables: with a body, the position and
 * heading kept as the previous ones, the position taken from the body and
 * the heading made the direction its rotation turns the z axis to, flattened
 * to the ground plane and of unit length (w 1). */
// NONMATCHING: 25/51, the same size: the base loads the division's 1.0 from the pool right
// after the first copy's load (`vmovss xmm2, [0x14d4e60]` at 0x42da42) and assigns the
// squares around it; the build loads it next to the division; the operations the same
void FUN_0042da30(Object0042da30 *self) /* derived name */
{
    if (Body0042da30 *body = self->body) {
        self->previousPosition = self->position;
        self->previousHeading = self->heading;
        self->position = body->position;
        const float x = body->rotation.x;
        const float y = body->rotation.y;
        const float z = body->rotation.z;
        const float w = body->rotation.w;
        const float inverse = 1.0f / (x * x + y * y + z * z + w * w);
        const float hx = 2.0f * (x * z + y * w) * inverse;
        const float hz = (w * w + z * z - x * x - y * y) * inverse;
        const float lengthSquared = hx * hx + hz * hz;
        float scale = 0.0f;
        if (lengthSquared - EPSILON * EPSILON > 0.0f)
            scale = 1.0f / sqrtf(lengthSquared);
        self->heading.set(hx * scale, 0.0f, hz * scale, 1.0f);
    }
}
