/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: returns the address of the field at +0x520; slot 23 of the
 * vtable at 0x16a7a50 (its pointer at 0x16a7b18), the vtable stored by
 * FUN_00297190 FUN_00297320; slot 23 of the vtable at 0x16a8260 (its pointer
 * at 0x16a8328), the vtable stored by FUN_002eec50; slot 23 of the vtable at
 * 0x16ac218 (its pointer at 0x16ac2e0), the vtable stored by FUN_00681b50
 * FUN_00684c00; slot 23 of the vtable at 0x16ac3a8 (its pointer at 0x16ac470),
 * the vtable stored by FUN_00684a90 FUN_00685840; and 13 more. The field's
 * type is not traced: its extent is the distance to the next field the slots
 * reach, held as bytes. Class and method unknown. */
u8 *FUN_0134a430(Object0134a660 *self) /* derived name */
{
    return self->unknown520;
}
