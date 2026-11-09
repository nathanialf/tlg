/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00c19e60
 * as a tail call; slot 5 of the vtable at 0x16b27d0 (stored by FUN_00a84bb0).
 * FUN_00c19e60 takes a second pointer, its fields at +0x18 and +0x30 read, its
 * type not traced. The record is the one FUN_00c19e60 works on; the return
 * type is not traced. */
struct Object00c19e60; /* derived name */

void FUN_00c19e60(Object00c19e60 *self, void *other); /* derived name */

void FUN_00a84d60(Object00c19e60 *self, void *other) /* derived name */
{
    FUN_00c19e60(self, other);
}
