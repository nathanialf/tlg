/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: decrements the int at +0x22c atomically (`lock dec`, the
 * result unused); slot 4 of the vtable at 0x16a7a50 (its pointer at
 * 0x16a7a80), the vtable stored by FUN_00297190 FUN_00297320; slot 4 of the
 * vtable at 0x16a7ce8 (its pointer at 0x16a7d18), the vtable stored by
 * FUN_002a8650 FUN_002a87b0 FUN_002a8810; slot 4 of the vtable at 0x16a7ea8
 * (its pointer at 0x16a7ed8), the vtable stored by FUN_002ae3c0 FUN_002aec50;
 * slot 4 of the vtable at 0x16a7f18 (its pointer at 0x16a7f48), the vtable
 * stored by FUN_002b4bf0 FUN_002b5080; and 111 more. Class and method unknown. */
void FUN_0134a3a0(Object0134a660 *self) /* derived name */
{
    __sync_fetch_and_sub(&self->unknown22c, 1);
}
