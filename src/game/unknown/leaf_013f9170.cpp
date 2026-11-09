/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16d55d8 (stored by FUN_013f6df0 FUN_013f9180), slot 2, as a tail call to
 * FUN_013f9180, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 3 (0x13f92b0): FUN_013f9180 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013f9180; /* derived name */

void FUN_013f9180(Object013f9180 *self); /* derived name */

void FUN_013f9170(Object013f9180 *self) /* derived name */
{
    FUN_013f9180(self);
}
