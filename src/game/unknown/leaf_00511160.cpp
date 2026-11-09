/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_008227e0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ab140 (stored by FUN_00510fa0);
 * 0x16c7608 (stored by FUN_00344a60); 0x16cb520 (stored by FUN_006743e0), slot
 * 1 (0x511170) the deleting destructor calling FUN_008227e0 before operator
 * delete. One body for the 3 vtables. Written as a free function on the base
 * record until the base destructor's row is named (a class form needs its D2
 * symbol). */
struct Object008227e0; /* derived name */

void FUN_008227e0(Object008227e0 *self); /* derived name */

void FUN_00511160(Object008227e0 *self) /* derived name */
{
    FUN_008227e0(self);
}
