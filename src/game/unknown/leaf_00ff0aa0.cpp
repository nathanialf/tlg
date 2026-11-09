/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00fef930
 * as a tail call; slot 3 of the vtable at 0x16c0538 (stored by FUN_00ffe8c0).
 * FUN_00fef930 takes six more arguments: 64-bit values in rsi, rdx, r8 and r9,
 * an int in ecx and a pointer on the stack tested for null; their types not
 * traced (the forwarder keeps all seven, as a tail call with a stack argument
 * needs the same incoming one). The record is the one FUN_00fef930 works on;
 * the return type is not traced. */
struct Object00fef930; /* derived name */

void FUN_00fef930(Object00fef930 *self, void *a, void *b, int c, void *d, void *e,
                  void *f); /* derived name */

void FUN_00ff0aa0(Object00fef930 *self, void *a, void *b, int c, void *d, void *e,
                  void *f) /* derived name */
{
    FUN_00fef930(self, a, b, c, d, e, f);
}
