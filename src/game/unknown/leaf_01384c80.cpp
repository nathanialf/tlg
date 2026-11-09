/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16b1898 (stored by FUN_009b4360 FUN_01385140), slot 0, as a tail call to
 * FUN_01385140, which stores that vtable itself and whose only other caller
 * is the deleting destructor in slot 1 (0x1384c90): FUN_01385140 is the same
 * class's base-object destructor (D2), not a base class's. Under D45 it is
 * the separate D1 the game compiler emits for the class's inline destructor,
 * a jump to the D2. Written as a free function on the record until the class
 * form can be written: it needs the D2's body (FUN_01385140, not yet
 * matched), the vtable at 0x16b1898 named by ruling (D14), since the D2
 * stores it, and the class's vtable emitted in the file (a key function or a
 * constructor defined there), without which an inline destructor is not
 * emitted. */
struct Object01385140; /* derived name */

void FUN_01385140(Object01385140 *self); /* derived name */

void FUN_01384c80(Object01385140 *self) /* derived name */
{
    FUN_01385140(self);
}
