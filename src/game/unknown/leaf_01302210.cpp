/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that calls FUN_01302220 with the object, its
 * first argument and its third (64-bit, `mov rdx, rcx`), the second unused, as
 * a tail call; slot 16 of the vtable at 0x16c3808 (its pointer at 0x16c3898),
 * the vtable stored by FUN_012ffc30 FUN_013001f0 FUN_013002e0. The argument
 * types and the return type are not traced. Class and method unknown. */
struct Object013007d0;

void FUN_01302220(Object013007d0 *self, void *first, void *third); /* derived name */

void FUN_01302210(Object013007d0 *self, void *first, void *, void *third) /* derived name */
{
    FUN_01302220(self, first, third);
}
