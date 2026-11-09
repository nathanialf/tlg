/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x50 when it is non-zero (the store only
 * on that branch); slot 11 of the vtable at 0x16b0788 (its pointer at
 * 0x16b07f0), the vtable stored by FUN_008ef2f0 FUN_008ef5c0; slot 11 of the
 * vtable at 0x16b0808 (its pointer at 0x16b0870), the vtable stored by
 * FUN_008ef5c0; slot 11 of the vtable at 0x16b54b8 (its pointer at 0x16b5520),
 * the vtable stored by FUN_008ef2f0 FUN_008ef5c0 FUN_008f2ec0 FUN_008f2f20
 * FUN_00b20380 FUN_00b20610 FUN_00b20670. Class and method unknown. */
struct Object00b209a0 { /* derived name */
    u8 unknown0[0x50];
    int unknown50;
};

void FUN_00b20990(Object00b209a0 *self) /* derived name */
{
    if (self->unknown50 != 0)
        self->unknown50 = 0;
}
