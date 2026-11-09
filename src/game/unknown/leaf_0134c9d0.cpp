/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16c74e0 (stored by FUN_001bd010 FUN_002370b0 FUN_00326c10 FUN_00537dd0
 * FUN_005ccd60 FUN_0069d690 FUN_0092ddb0 FUN_009c42e0 FUN_00b389c0
 * FUN_00b4d530 FUN_00bf1e30 FUN_00c93c40 FUN_00ce9810 FUN_00d00e40
 * FUN_00d1ffc0 FUN_00e10cd0 FUN_011004c0 FUN_0134c9e0), slot 0, as a tail call
 * to FUN_0134c9e0, which stores that vtable itself and whose only other caller
 * is the deleting destructor in slot 1 (0x134cb00): FUN_0134c9e0 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0134c9e0; /* derived name */

void FUN_0134c9e0(Object0134c9e0 *self); /* derived name */

void FUN_0134c9d0(Object0134c9e0 *self) /* derived name */
{
    FUN_0134c9e0(self);
}
