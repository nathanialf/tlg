/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16cb078 (stored by FUN_0052e170 FUN_005f3970 FUN_005fb1d0 FUN_006233e0
 * FUN_007dfc40 FUN_007f50d0 FUN_0092ddb0 FUN_0096f230 FUN_00a31aa0
 * FUN_00ad9d20 FUN_00b4d530 FUN_00bf1e30 FUN_00bf9780 FUN_00bfe2a0
 * FUN_00c93c40 FUN_00e10cd0 FUN_013586b0), slot 0, as a tail call to
 * FUN_013586b0, which stores that vtable itself and whose only other caller
 * is the deleting destructor in slot 1 (0x1358800): FUN_013586b0 is the same
 * class's base-object destructor (D2), not a base class's. Under D45 it is
 * the separate D1 the game compiler emits for the class's inline destructor,
 * a jump to the D2. Written as a free function on the record until the class
 * form can be written: it needs the D2's body (FUN_013586b0, not yet
 * matched), the vtable at 0x16cb078 named by ruling (D14), since the D2
 * stores it, and the class's vtable emitted in the file (a key function or a
 * constructor defined there), without which an inline destructor is not
 * emitted. */
struct Object013586b0; /* derived name */

void FUN_013586b0(Object013586b0 *self); /* derived name */

void FUN_01358420(Object013586b0 *self) /* derived name */
{
    FUN_013586b0(self);
}
