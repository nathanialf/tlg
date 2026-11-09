/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00db3930
 * as a tail call; slot 2 of the vtable at 0x16bc108 (stored by FUN_00db4100).
 * FUN_00db3930 takes two more 64-bit arguments (rsi and rdx, kept in r15 and
 * r14 at entry), their types not traced. The record is the one FUN_00db3930
 * works on; the return type is not traced. */
struct Object00db3930; /* derived name */

void FUN_00db3930(Object00db3930 *self, void *a, void *b); /* derived name */

void FUN_013c83f0(Object00db3930 *self, void *a, void *b) /* derived name */
{
    FUN_00db3930(self, a, b);
}
