/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00a8eae0
 * as a tail call; slot 23 of the vtable at 0x16a96d0 (stored by FUN_003fbc60
 * FUN_003fc620). FUN_00a8eae0 takes four 64-bit arguments saved at entry,
 * their types not traced. The record is the one FUN_00a8eae0 works on; the
 * return type is not traced. */
struct Object00a8eae0; /* derived name */

void FUN_00a8eae0(Object00a8eae0 *self, void *a, void *b, void *c, void *d); /* derived name */

void FUN_00403620(Object00a8eae0 *self, void *a, void *b, void *c, void *d) /* derived name */
{
    FUN_00a8eae0(self, a, b, c, d);
}
