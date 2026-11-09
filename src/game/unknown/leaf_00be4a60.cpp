/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the pointer at +0xd8; slot 5 of the vtable at
 * 0x16b79f0 (its pointer at 0x16b7a28), the vtable stored by FUN_00be4000
 * FUN_00be48c0 FUN_00be4960; slot 6 (FUN_00be4a70) returns the int at +0xe0.
 * The pointer's target is not traced. Class and method unknown. */
struct Target00be4a60; /* derived name */

struct Object00be4a60 { /* derived name */
    u8 unknown0[0xd8];
    Target00be4a60 *unknownd8;
};

Target00be4a60 *FUN_00be4a60(const Object00be4a60 *self) /* derived name */
{
    return self->unknownd8;
}
