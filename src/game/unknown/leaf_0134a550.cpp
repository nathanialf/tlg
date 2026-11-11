/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: copies the 32-bit value its argument points to into +0x504
 * and sets bit 4 of the byte at +0x20; slot 29 of the vtable at 0x16a7a50 (its
 * pointer at 0x16a7b48), the vtable stored by FUN_00297190 FUN_00297320; slot
 * 29 of the vtable at 0x16a8260 (its pointer at 0x16a8358), the vtable stored
 * by FUN_002eec50; slot 29 of the vtable at 0x16ac218 (its pointer at
 * 0x16ac310), the vtable stored by FUN_00681b50 FUN_00684c00; slot 29 of the
 * vtable at 0x16ac3a8 (its pointer at 0x16ac4a0), the vtable stored by
 * FUN_00684a90 FUN_00685840; and 2 more. Class and method unknown. */
void FUN_0134a550(Object0134a660 *self, const u32 *value) /* derived name */
{
    self->unknown504 = *value;
    self->unknown20 |= 0x10;
}
