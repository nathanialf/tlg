/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: returns the address of the field at +0x540; slot 15 of the
 * vtable at 0x16a7a50 (its pointer at 0x16a7ad8), the vtable stored by
 * FUN_00297190 FUN_00297320; slot 15 of the vtable at 0x16a8260 (its pointer
 * at 0x16a82e8), the vtable stored by FUN_002eec50; slot 15 of the vtable at
 * 0x16ac218 (its pointer at 0x16ac2a0), the vtable stored by FUN_00681b50
 * FUN_00684c00; slot 15 of the vtable at 0x16ac3a8 (its pointer at 0x16ac430),
 * the vtable stored by FUN_00684a90 FUN_00685840; and 13 more. The field's
 * type is not traced: its extent is the distance to the next field the slots
 * reach, held as bytes. Class and method unknown. */
Name *FUN_0134a3b0(Object0134a660 *self) /* derived name */
{
    return &self->name540;
}
