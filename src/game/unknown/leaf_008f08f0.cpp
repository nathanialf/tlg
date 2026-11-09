/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x50 of the record its pointer at +0x38
 * points to; slot 7 of the vtable at 0x16b06b0 (its pointer at 0x16b06f8), the
 * vtable stored by FUN_008ef8a0 FUN_008efe80; slot 7 of the vtable at
 * 0x16b8db8 (its pointer at 0x16b8e00), the vtable stored by FUN_00ca3e70.
 * Class and method unknown. */
struct Target008f08f0 { /* derived name */
    u8 unknown0[0x50];
    int unknown50;
};

struct Object008f08f0 { /* derived name */
    u8 unknown0[0x38];
    Target008f08f0 *unknown38;
};

int FUN_008f08f0(const Object008f08f0 *self) /* derived name */
{
    return self->unknown38->unknown50;
}
