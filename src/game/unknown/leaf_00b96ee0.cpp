/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00b997d0
 * as a tail call; slot 5 of the vtable at 0x16b7148 (stored by FUN_00b8c400
 * FUN_00b8e610). FUN_00b997d0 takes a second pointer (kept in r12 at entry),
 * its type not traced. The record is the one FUN_00b997d0 works on; the return
 * type is not traced. */
struct Object00b997d0; /* derived name */

void FUN_00b997d0(Object00b997d0 *self, void *other); /* derived name */

void FUN_00b96ee0(Object00b997d0 *self, void *other) /* derived name */
{
    FUN_00b997d0(self, other);
}
