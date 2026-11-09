/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16ccf38 (stored by FUN_00958ef0 FUN_0137f610), slot 0, as a tail call to
 * FUN_0137f610, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 1 (0x137f5f0): FUN_0137f610 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0137f610; /* derived name */

void FUN_0137f610(Object0137f610 *self); /* derived name */

void FUN_0137f5e0(Object0137f610 *self) /* derived name */
{
    FUN_0137f610(self);
}
