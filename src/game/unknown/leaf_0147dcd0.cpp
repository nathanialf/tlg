/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: calls FUN_01240d00 on the object with its argument and 1 as a
 * tail call, as FUN_0147dca0 does with 0; slot 8 counted from the nearest
 * stored vtable, at 0x16d6bf0 (its pointer at 0x16d6c40), the vtable stored by
 * FUN_0122be10; slot 8 of the vtable at 0x16d73e8 (its pointer at 0x16d7438),
 * the vtable stored by FUN_0122be10. The argument's type is not traced. Class
 * and method unknown. */
struct Object01240d00; /* derived name */

void FUN_01240d00(Object01240d00 *self, void *argument, int); /* derived name */

void FUN_0147dcd0(Object01240d00 *self, void *argument) /* derived name */
{
    FUN_01240d00(self, argument, 1);
}
