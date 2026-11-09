/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor (D1) of the class whose vtable is at
 * 0x16c74e0 (stored by FUN_001bd010 FUN_002370b0 FUN_00326c10 FUN_00537dd0
 * FUN_005ccd60 FUN_0069d690 FUN_0092ddb0 FUN_009c42e0 FUN_00b389c0
 * FUN_00b4d530 FUN_00bf1e30 FUN_00c93c40 FUN_00ce9810 FUN_00d00e40
 * FUN_00d1ffc0 FUN_00e10cd0 FUN_011004c0 FUN_0134c9e0), slot 0, as a tail
 * call to FUN_0134c9e0, which stores that vtable itself and whose only other
 * caller is the deleting destructor in slot 1 (0x134cb00): FUN_0134c9e0 is
 * the same class's base-object destructor (D2), not a base class's. Under D45
 * it is the separate D1 the game compiler emits for the class's inline
 * destructor, a jump to the D2. Written as a free function on the record
 * until the class form can be written: it needs the D2's body (FUN_0134c9e0,
 * not yet matched), the vtable at 0x16c74e0 named by ruling (D14), since the
 * D2 stores it, and the class's vtable emitted in the file (a key function or
 * a constructor defined there), without which an inline destructor is not
 * emitted. */
struct Object0134c9e0; /* derived name */

void FUN_0134c9e0(Object0134c9e0 *self); /* derived name */

void FUN_0134c9d0(Object0134c9e0 *self) /* derived name */
{
    FUN_0134c9e0(self);
}
