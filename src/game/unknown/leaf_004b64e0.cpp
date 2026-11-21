/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_math.h"

static const float EPSILON = 1e-5f; /* derived name: as leaf_00206a90.cpp's */

/* a point turned by a rotation (tlg_game_object00774560.h) */
Float4A FUN_01343bb0(const Float4A &point, const Float4A &rotation); /* derived name */

/* derived names: the body at +0x28: its position at +0x120 and its rotation
 * at +0x140 */
struct Body004b64e0 { /* derived name */
    u8 unknown0[0x120];
    Float4A position; /* +0x120 */
    u8 unknown130[0x10];
    Float4A rotation; /* +0x140 */
};

/* derived names: the class whose vtable is at 0x16aa290 as slot 11 sees it */
struct Object004b64e0 { /* derived name */
    u8 unknown0[0x28];
    Body004b64e0 *body; /* +0x28 */
};

/* derived names: slot 11 of the vtable at 0x16aa290: with a body, its
 * position, and the direction its rotation turns the x axis to, flattened to
 * the ground plane and of unit length (its w the turned axis's). */
void FUN_004b64e0(Object004b64e0 *self, Float4A *position, Float4A *heading) /* derived name */
{
    if (Body004b64e0 *body = self->body) {
        *position = body->position;
        const Float4A turned = FUN_01343bb0(Float4A(1.0f, 0.0f, 0.0f, 0.0f), body->rotation);
        const Float4A flat(turned.x, 0.0f, turned.z, turned.w);
        const float lengthSquared = flat.x * flat.x + flat.z * flat.z;
        float scale = 0.0f;
        if (lengthSquared - EPSILON * EPSILON > 0.0f)
            scale = 1.0f / sqrtf(lengthSquared);
        heading->set(flat.x * scale, 0.0f, flat.z * scale, flat.w);
    }
}
