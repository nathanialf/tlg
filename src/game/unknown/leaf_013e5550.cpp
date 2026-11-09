/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x8, then calls FUN_013e5560
 * on the object with 3, as a tail call. The pointer's target and the return
 * type are not traced; slot 3 of the vtable at 0x16d4cf0 (its pointer at
 * 0x16d4d18), the vtable stored by FUN_00fcc550. Class and method unknown. */
struct Target013e5550; /* derived name */

struct Object013e5550 { /* derived name */
    u8 unknown0[8];
    Target013e5550 *unknown8;
};

void FUN_013e5560(Object013e5550 *self, int); /* derived name */

void FUN_013e5550(Object013e5550 *self, Target013e5550 *target) /* derived name */
{
    self->unknown8 = target;
    FUN_013e5560(self, 3);
}
