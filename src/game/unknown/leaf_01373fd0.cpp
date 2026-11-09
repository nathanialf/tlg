/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the pointer at +0x38; slot 15 of the vtable at
 * 0x16b06b0 (its pointer at 0x16b0738), the vtable stored by FUN_008ef8a0
 * FUN_008efe80; slot 15 of the vtable at 0x16b8db8 (its pointer at 0x16b8e40),
 * the vtable stored by FUN_00ca3e70; slot 15 of the vtable at 0x16b9048 (its
 * pointer at 0x16b90d0), the vtable stored by FUN_00cb3170 FUN_013ad610; slot
 * 8 (FUN_01373fc0) returns the address of +0x68 of its target. Class and
 * method unknown. */
struct Target01373fc0 { /* derived name */
    u8 unknown0[0x68];
    u8 unknown68[4]; /* its address returned by FUN_01373fc0; type and size not traced */
};

struct Object01373fc0 { /* derived name */
    u8 unknown0[0x38];
    Target01373fc0 *
        unknown38; /* returned through by FUN_01373fc0 (slot 8), cleared by FUN_01373fd0 (slot 15) */
};

void FUN_01373fd0(Object01373fc0 *self) /* derived name */
{
    self->unknown38 = 0;
}
