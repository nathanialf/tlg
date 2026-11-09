/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that calls FUN_01240d00, the slot before it,
 * directly with its two arguments and 0 as a third as a tail call; slot 8
 * counted from the nearest stored vtable, at 0x16d6c48 (its pointer at
 * 0x16d6c98), the vtable stored by FUN_0122be10; slot 8 of the vtable at
 * 0x16d7440 (its pointer at 0x16d7490), the vtable stored by FUN_0122be10.
 * FUN_00fae1e0 and FUN_01240d00 are 4,531-byte bodies of one shape. The
 * argument types are not traced (the 0 a 32-bit zero, written int); the return
 * type is not traced. Class and method unknown. */
struct Object01240d00; /* derived name */

void FUN_01240d00(Object01240d00 *self, void *argument, int); /* derived name */

void FUN_0147dca0(Object01240d00 *self, void *argument) /* derived name */
{
    FUN_01240d00(self, argument, 0);
}
