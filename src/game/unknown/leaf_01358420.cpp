/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16cb078 (stored by FUN_0052e170 FUN_005f3970 FUN_005fb1d0 FUN_006233e0
 * FUN_007dfc40 FUN_007f50d0 FUN_0092ddb0 FUN_0096f230 FUN_00a31aa0
 * FUN_00ad9d20 FUN_00b4d530 FUN_00bf1e30 FUN_00bf9780 FUN_00bfe2a0
 * FUN_00c93c40 FUN_00e10cd0 FUN_013586b0), slot 0, as a tail call to
 * FUN_013586b0, which stores that vtable itself and whose only other caller is
 * the deleting destructor in slot 1 (0x1358800): FUN_013586b0 is the same
 * class's base-object destructor (D2), not a base class's. A separate D1
 * jumping to its D2 is not what the public 4.0.0 emits for a strong or an
 * inline definition under -mconstructor-aliases (an alias, or the D1 replaced
 * by the D2): an open question for the supervisor. Written as a free function
 * on the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013586b0; /* derived name */

void FUN_013586b0(Object013586b0 *self); /* derived name */

void FUN_01358420(Object013586b0 *self) /* derived name */
{
    FUN_013586b0(self);
}
