/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 0 in the int at +0x238; slot 10 of the vtable at
 * 0x16a8748 (its pointer at 0x16a87a8), the vtable stored by FUN_003442a0;
 * slot 10 of the vtable at 0x16a8910 (its pointer at 0x16a8970), the vtable
 * stored by FUN_0035b0a0; slot 10 of the vtable at 0x16aae78 (its pointer at
 * 0x16aaed8), the vtable stored by FUN_0050b980; slot 10 of the vtable at
 * 0x16ab058 (its pointer at 0x16ab0b8), the vtable stored by FUN_00510870; and
 * 4 more. Class and method unknown. */
struct Object00822430 { /* derived name */
    u8 unknown0[0x238];
    int unknown238;
};

void FUN_00822430(Object00822430 *self) /* derived name */
{
    self->unknown238 = 0;
}
