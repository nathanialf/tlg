/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134a660.h"

/* derived names: passes the address of the int at +0x22c to FUN_01331c10 as a
 * tail call; slot 3 of the vtable at 0x16a7a50 (its pointer at 0x16a7a78), the
 * vtable stored by FUN_00297190 FUN_00297320; slot 3 of the vtable at
 * 0x16a7ce8 (its pointer at 0x16a7d10), the vtable stored by FUN_002a8650
 * FUN_002a87b0 FUN_002a8810; slot 3 of the vtable at 0x16a7ea8 (its pointer at
 * 0x16a7ed0), the vtable stored by FUN_002ae3c0 FUN_002aec50; slot 3 of the
 * vtable at 0x16a7f18 (its pointer at 0x16a7f40), the vtable stored by
 * FUN_002b4bf0 FUN_002b5080; and 2 more. FUN_01331c10 takes the int with lock
 * cmpxchg (incrementing it, waiting through imports otherwise) and
 * FUN_0134a3a0 (slot 4) decrements it atomically: a lock count taken and
 * released, its meaning not traced. Class and method unknown. */
void FUN_01331c10(int *count); /* derived name */

void FUN_0134a390(Object0134a660 *self) /* derived name */
{
    FUN_01331c10(&self->unknown22c);
}
