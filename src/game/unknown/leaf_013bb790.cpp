/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0139d760, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16bab08 (stored by FUN_00b7d020
 * FUN_00d70ae0 FUN_00d88310 FUN_0139d760), slot 1 (0x13bb7a0) the deleting
 * destructor calling FUN_0139d760 before operator delete. Written as a free
 * function on the record until the destructor's row is named (a class form
 * needs its D2 symbol). */
struct Object0139d760; /* derived name */

void FUN_0139d760(Object0139d760 *self); /* derived name */

void FUN_013bb790(Object0139d760 *self) /* derived name */
{
    FUN_0139d760(self);
}
