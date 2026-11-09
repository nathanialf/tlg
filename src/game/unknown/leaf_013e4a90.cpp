/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013e1ea0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ca5b8 (stored by FUN_00fba720
 * FUN_013e1ea0); 0x16d48f0 (stored by FUN_00fba720), slot 1 (0x13e4aa0) the
 * deleting destructor calling FUN_013e1ea0 before operator delete. One body
 * for the 2 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object013e1ea0; /* derived name */

void FUN_013e1ea0(Object013e1ea0 *self); /* derived name */

void FUN_013e4a90(Object013e1ea0 *self) /* derived name */
{
    FUN_013e1ea0(self);
}
