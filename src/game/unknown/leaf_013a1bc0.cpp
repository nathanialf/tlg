/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16b7e18 (stored by FUN_00bff9d0 FUN_013a1bf0), slot 0, as a tail call to
 * FUN_013a1bf0, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 1 (0x13a1bd0): FUN_013a1bf0 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013a1bf0; /* derived name */

void FUN_013a1bf0(Object013a1bf0 *self); /* derived name */

void FUN_013a1bc0(Object013a1bf0 *self) /* derived name */
{
    FUN_013a1bf0(self);
}
