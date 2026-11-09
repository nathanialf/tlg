/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16b1508 (stored by FUN_0096a0a0 FUN_0137fd40), slot 0, as a tail call to
 * FUN_0137fd40, which stores that vtable itself and whose only other caller
 * is the deleting destructor in slot 1 (0x137fd20): FUN_0137fd40 is the same
 * class's base-object destructor (D2), not a base class's. Under D45 it is
 * the separate D1 the game compiler emits for the class's inline destructor,
 * a jump to the D2. Written as a free function on the record until the class
 * form can be written: it needs the D2's body (FUN_0137fd40, not yet
 * matched), the vtable at 0x16b1508 named by ruling (D14), since the D2
 * stores it, and the class's vtable emitted in the file (a key function or a
 * constructor defined there), without which an inline destructor is not
 * emitted. */
struct Object0137fd40; /* derived name */

void FUN_0137fd40(Object0137fd40 *self); /* derived name */

void FUN_0137fd10(Object0137fd40 *self) /* derived name */
{
    FUN_0137fd40(self);
}
