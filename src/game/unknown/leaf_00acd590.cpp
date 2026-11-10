/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: resets the float at +0x18 to zero and the floats at +0x1c
 * and +0x20 to minus infinity (the first two as one 64-bit store); slot 5 of
 * the vtable at 0x16b3910 (its pointer at 0x16b3948), the vtable stored by
 * FUN_00abf490. The floats' meaning is not traced. Class and method unknown. */
struct Object00acd590 { /* derived name */
    u8 unknown0[0x18];
    float unknown18;
    float unknown1c;
    float unknown20;
};

void FUN_00acd590(Object00acd590 *self) /* derived name */
{
    self->unknown18 = 0.0f;
    self->unknown1c = -HUGE_VALF;
    self->unknown20 = -HUGE_VALF;
}
