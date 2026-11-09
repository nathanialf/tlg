/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16b18e0 (stored by FUN_009b44d0 FUN_01384f20), slot 0, as a tail call to
 * FUN_01384f20, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 1 (0x1384cc0): FUN_01384f20 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01384f20; /* derived name */

void FUN_01384f20(Object01384f20 *self); /* derived name */

void FUN_01384cb0(Object01384f20 *self) /* derived name */
{
    FUN_01384f20(self);
}
