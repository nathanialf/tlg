/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16d4318 (stored by FUN_00f9ab50 FUN_013e14a0), slot 2, as a tail call to
 * FUN_013e14a0, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 3 (0x13e15d0): FUN_013e14a0 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013e14a0; /* derived name */

void FUN_013e14a0(Object013e14a0 *self); /* derived name */

void FUN_013e1490(Object013e14a0 *self) /* derived name */
{
    FUN_013e14a0(self);
}
