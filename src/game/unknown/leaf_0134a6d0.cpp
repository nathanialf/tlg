/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: clears the bits of its argument in the 32-bit word at +0x550;
 * slot 41 of the vtable at 0x16a7a50 (its pointer at 0x16a7ba8), the vtable
 * stored by FUN_00297190 FUN_00297320; slot 41 of the vtable at 0x16a8260 (its
 * pointer at 0x16a83b8), the vtable stored by FUN_002eec50; slot 41 of the
 * vtable at 0x16ac218 (its pointer at 0x16ac370), the vtable stored by
 * FUN_00681b50 FUN_00684c00; slot 41 of the vtable at 0x16ac3a8 (its pointer
 * at 0x16ac500), the vtable stored by FUN_00684a90 FUN_00685840; and 13 more.
 * Class and method unknown. */
void FUN_0134a6d0(Object0134a660 *self, u32 bits) /* derived name */
{
    self->unknown550 &= ~bits;
}
