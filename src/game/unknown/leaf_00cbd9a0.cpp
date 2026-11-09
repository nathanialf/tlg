/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its argument on to FUN_00cbd9b0
 * as a tail call, the object unused; slot 1 of the vtable at 0x16b9140 (its
 * pointer at 0x16b9158), no storing constructor listed. The argument's type
 * and the return type are not traced. Class and method unknown. */
struct Object00cbd9a0;

void FUN_00cbd9b0(void *argument); /* derived name */

void FUN_00cbd9a0(Object00cbd9a0 *self, void *argument) /* derived name */
{
    FUN_00cbd9b0(argument);
}
