/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_0125c000
 * as a tail call; slot 3 of the vtable at 0x16c26e0 (stored by FUN_0126a510).
 * FUN_0125c000 takes six more arguments: 64-bit values in rsi, rdx, r8 and r9,
 * an int in ecx and a pointer on the stack tested for null; their types not
 * traced (the forwarder keeps all seven, as a tail call with a stack argument
 * needs the same incoming one); FUN_00fef930 has the same size and shape. The
 * record is the one FUN_0125c000 works on; the return type is not traced. */
struct Object0125c000; /* derived name */

void FUN_0125c000(Object0125c000 *self, void *a, void *b, int c, void *d, void *e,
                  void *f); /* derived name */

void FUN_0125d170(Object0125c000 *self, void *a, void *b, int c, void *d, void *e,
                  void *f) /* derived name */
{
    FUN_0125c000(self, a, b, c, d, e, f);
}
