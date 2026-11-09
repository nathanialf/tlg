/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: calls FUN_00fae1e0 on the object with its argument and 1 as a
 * tail call, as FUN_013e2930 does with 0; slot 8 counted from the nearest
 * stored vtable, at 0x16d3fe0 (its pointer at 0x16d4030), the vtable stored by
 * FUN_00f9ab50; slot 8 of the vtable at 0x16d4aa8 (its pointer at 0x16d4af8),
 * the vtable stored by FUN_00f9ab50. The argument's type is not traced. Class
 * and method unknown. */
struct Object00fae1e0; /* derived name */

void FUN_00fae1e0(Object00fae1e0 *self, void *argument, int); /* derived name */

void FUN_013e2960(Object00fae1e0 *self, void *argument) /* derived name */
{
    FUN_00fae1e0(self, argument, 1);
}
