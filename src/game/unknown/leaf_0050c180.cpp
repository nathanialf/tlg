/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00822190, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16a8910 (stored by FUN_0035b0a0);
 * 0x16aae78 (stored by FUN_0050b980), slot 1 (0x50c190) the deleting
 * destructor calling FUN_00822190 before operator delete. One body for the 2
 * vtables. Written as a free function on the base record until the base
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00822190; /* derived name */

void FUN_00822190(Object00822190 *self); /* derived name */

void FUN_0050c180(Object00822190 *self) /* derived name */
{
    FUN_00822190(self);
}
