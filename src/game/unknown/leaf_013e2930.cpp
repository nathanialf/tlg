/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that calls FUN_00fae1e0, the slot before it,
 * directly with its two arguments and 0 as a third as a tail call; slot 8
 * counted from the nearest stored vtable, at 0x16d4038 (its pointer at
 * 0x16d4088), the vtable stored by FUN_00f9ab50; slot 8 of the vtable at
 * 0x16d4b00 (its pointer at 0x16d4b50), the vtable stored by FUN_00f9ab50.
 * FUN_00fae1e0 and FUN_01240d00 are 4,531-byte bodies of one shape. The
 * argument types are not traced (the 0 a 32-bit zero, written int); the return
 * type is not traced. Class and method unknown. */
struct Object00fae1e0; /* derived name */

void FUN_00fae1e0(Object00fae1e0 *self, void *argument, int); /* derived name */

void FUN_013e2930(Object00fae1e0 *self, void *argument) /* derived name */
{
    FUN_00fae1e0(self, argument, 0);
}
