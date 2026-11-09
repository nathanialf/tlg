/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00fb1d70
 * as a tail call; slot 8 of the vtable at 0x16d4948 (stored by FUN_00fba720
 * FUN_013e49b0 FUN_013e4a20). FUN_00fb1d70 takes two more 64-bit arguments
 * (rsi, a record whose pointer at +0x8d8 it reads, and rdx), their types not
 * traced. The record is the one FUN_00fb1d70 works on; the return type is not
 * traced. Slot 7 of the same vtable is FUN_00fb1d70 itself. */
struct Object00fb1d70; /* derived name */

void FUN_00fb1d70(Object00fb1d70 *self, void *a, void *b); /* derived name */

void FUN_013e30a0(Object00fb1d70 *self, void *a, void *b) /* derived name */
{
    FUN_00fb1d70(self, a, b);
}
