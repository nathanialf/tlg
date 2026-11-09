/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_008f2d70 with the object and the address of the
 * field at +0x120 of the record the pointer at +0x28 holds, null skipped, as a
 * tail call; slot 13 of the vtable at 0x16b0788 (its pointer at 0x16b0800).
 * The field's type and the return type are not traced. Class and method
 * unknown. */
struct Record008f3130 { /* derived name */
    u8 unknown0[0x120];
    u8 unknown120; /* type not traced; its address is passed */
};

struct Object008f3130 { /* derived name */
    u8 unknown0[0x28];
    Record008f3130 *unknown28;
};

void FUN_008f2d70(Object008f3130 *self, void *argument); /* derived name */

void FUN_008f3130(Object008f3130 *self) /* derived name */
{
    if (self->unknown28) {
        FUN_008f2d70(self, &self->unknown28->unknown120);
    }
}
