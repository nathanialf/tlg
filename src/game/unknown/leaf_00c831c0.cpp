/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: passes its third argument to FUN_00cfeb10, a variadic
 * function (al 0, no vector arguments) that prints its first variadic argument
 * through vprintf with the format "%s", as a tail call; slot 6 of the vtable
 * at 0x16b8980 (its pointer at 0x16b89c0), no storing constructor listed. The
 * second argument is not used and its type is not traced. Class and method
 * unknown. */
struct Object00c831c0; /* derived name */

void FUN_00cfeb10(Object00c831c0 *self, ...); /* derived name */

void FUN_00c831c0(Object00c831c0 *self, int, const char *message) /* derived name */
{
    FUN_00cfeb10(self, message);
}
