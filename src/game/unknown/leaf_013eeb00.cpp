/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16d5228 (stored by FUN_01006780 FUN_013eeb10), slot 2, as a tail call to
 * FUN_013eeb10, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 3 (0x13eec40): FUN_013eeb10 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013eeb10; /* derived name */

void FUN_013eeb10(Object013eeb10 *self); /* derived name */

void FUN_013eeb00(Object013eeb10 *self) /* derived name */
{
    FUN_013eeb10(self);
}
