/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_00ab9510
 * as a tail call; slot 9 of the vtable at 0x16a79e8 (stored by FUN_00296100
 * FUN_002962e0). The record is the one FUN_00ab9510 works on; the return type
 * is not traced. */
struct Object00ab9510; /* derived name */

void FUN_00ab9510(Object00ab9510 *self); /* derived name */

void FUN_00296740(Object00ab9510 *self) /* derived name */
{
    FUN_00ab9510(self);
}
