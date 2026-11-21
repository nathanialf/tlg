/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_math.h"

/* the butterfly's flying states (func_004e7580.cpp) */
extern Name D_57d92c0; /* "BUTTERFLY_fly_start" */
extern Name D_57d92f0; /* "BUTTERFLY_fly_loop" */
extern Name D_57d92f4; /* "BUTTERFLY_fly_rest" */
extern Name D_57d92c4; /* "BUTTERFLY_fly_end" */

/* derived names: the class whose vtable is at 0x16aa5d8 (stored by its
 * constructor; leaf_004e22d0.cpp) as slot 22 sees it: its state's name at
 * +0x11c and, while it flies, an offset point at +0x280 and a rotation at
 * +0x290 */
struct Object004e6d40 { /* derived name */
    u8 unknown0[0x11c];
    Name state; /* +0x11c (derived name) */
    u8 unknown120[0x160];
    Float4A offset;   /* +0x280 (derived name) */
    Float4A rotation; /* +0x290 (derived name) */
};

/* derived names: slot 22 of the base class (slot 22 of the vtable at
 * 0x16aa3c8 too), called directly by the override; typed with the object
 * it is given */
void FUN_00502410(Object004e6d40 *self, void *argument, Float4A *position,
                  Float4A *rotation); /* derived name */

/* the product of two rotations (tlg_game_object00774560.h) */
Float4A FUN_013439c0(const Float4A &first, const Float4A &second); /* derived name */

/* derived names: slot 22 of the vtable at 0x16aa5d8: the base class's
 * position and rotation, then, in any of the four flying states, the
 * position moved by the offset (its w the offset's) and the rotation turned
 * by the object's. */
void FUN_004e6d40(Object004e6d40 *self, void *argument, Float4A *position,
                  Float4A *rotation) /* derived name */
{
    FUN_00502410(self, argument, position, rotation);
    if (self->state == D_57d92c0 || self->state == D_57d92f0 || self->state == D_57d92f4 ||
        self->state == D_57d92c4) {
        *position = Float4A(position->x + self->offset.x, position->y + self->offset.y,
                            position->z + self->offset.z, self->offset.w);
        *rotation = FUN_013439c0(self->rotation, *rotation);
    }
}
