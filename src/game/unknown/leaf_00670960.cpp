/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00822440, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16a8980 (stored by FUN_0035b210);
 * 0x16ac108 (stored by FUN_00670560), slot 1 (0x670970) the deleting
 * destructor calling FUN_00822440 before operator delete. One body for the 2
 * vtables. Written as a free function on the base record until the base
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00822440; /* derived name */

void FUN_00822440(Object00822440 *self); /* derived name */

void FUN_00670960(Object00822440 *self) /* derived name */
{
    FUN_00822440(self);
}
