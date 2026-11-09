/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16cb0c0 (stored by FUN_002370b0 FUN_0052e170 FUN_00537dd0 FUN_0069d690
 * FUN_008068c0 FUN_009c42e0 FUN_00af1a70 FUN_00b790b0 FUN_01358510), slot 0,
 * as a tail call to FUN_01358510, which stores that vtable itself and whose
 * only other caller is the deleting destructor in slot 1 (0x1358690):
 * FUN_01358510 is the same class's base-object destructor (D2), not a base
 * class's. A separate D1 jumping to its D2 is not what the public 4.0.0 emits
 * for a strong or an inline definition under -mconstructor-aliases (an alias,
 * or the D1 replaced by the D2): an open question for the supervisor. Written
 * as a free function on the record until the destructor's row is named (a
 * class form needs its D2 symbol). */
struct Object01358510; /* derived name */

void FUN_01358510(Object01358510 *self); /* derived name */

void FUN_01358430(Object01358510 *self) /* derived name */
{
    FUN_01358510(self);
}
