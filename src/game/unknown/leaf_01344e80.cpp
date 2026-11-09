/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16c70a8 (stored by FUN_001db8b0 FUN_01344e90), slot 0, as a tail call to
 * FUN_01344e90, which stores that vtable itself and whose only other caller
 * is the deleting destructor in slot 1 (0x1345590): FUN_01344e90 is the same
 * class's base-object destructor (D2), not a base class's. Under D45 it is
 * the separate D1 the game compiler emits for the class's inline destructor,
 * a jump to the D2. Written as a free function on the record until the class
 * form can be written: it needs the D2's body (FUN_01344e90, not yet
 * matched), the vtable at 0x16c70a8 named by ruling (D14), since the D2
 * stores it, and the class's vtable emitted in the file (a key function or a
 * constructor defined there), without which an inline destructor is not
 * emitted. */
struct Object01344e90; /* derived name */

void FUN_01344e90(Object01344e90 *self); /* derived name */

void FUN_01344e80(Object01344e90 *self) /* derived name */
{
    FUN_01344e90(self);
}
