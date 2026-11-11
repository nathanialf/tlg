/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: copies the 8 bytes its argument points to into +0x4fc; slot
 * 27 of the vtable at 0x16a7a50 (its pointer at 0x16a7b38), the vtable stored
 * by FUN_00297190 FUN_00297320; slot 27 of the vtable at 0x16a8260 (its
 * pointer at 0x16a8348), the vtable stored by FUN_002eec50; slot 27 of the
 * vtable at 0x16ac218 (its pointer at 0x16ac300), the vtable stored by
 * FUN_00681b50 FUN_00684c00; slot 27 of the vtable at 0x16ac3a8 (its pointer
 * at 0x16ac490), the vtable stored by FUN_00684a90 FUN_00685840; and 13 more.
 * Class and method unknown. */
void FUN_0134a530(Object0134a660 *self, const Value0134a530 *value) /* derived name */
{
    self->unknown4fc = *value;
}
