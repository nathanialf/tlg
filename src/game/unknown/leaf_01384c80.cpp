/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16b1898 (stored by FUN_009b4360 FUN_01385140), slot 0, as a tail call to
 * FUN_01385140, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 1 (0x1384c90): FUN_01385140 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01385140; /* derived name */

void FUN_01385140(Object01385140 *self); /* derived name */

void FUN_01384c80(Object01385140 *self) /* derived name */
{
    FUN_01385140(self);
}
