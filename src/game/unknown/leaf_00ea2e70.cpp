/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00e9a380 takes the address of (lea at
 * 0xe9a494): calls FUN_00e9e360 with the pointer at +0x10 and the object, as a
 * tail call. The types and the return type are not traced. Class and method
 * unknown. */
struct Target00ea2e70; /* derived name */

struct Object00ea2e70 { /* derived name */
    u8 unknown0[0x10];
    Target00ea2e70 *unknown10;
};

void FUN_00e9e360(Target00ea2e70 *target, Object00ea2e70 *object); /* derived name */

void FUN_00ea2e70(Object00ea2e70 *self) /* derived name */
{
    FUN_00e9e360(self->unknown10, self);
}
