/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013e1850, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ca330 (stored by FUN_00f9ab50
 * FUN_013e1850); 0x16d3fe0 (stored by FUN_00f9ab50); 0x16d4038 (stored by
 * FUN_00f9ab50); 0x16d4aa8 (stored by FUN_00f9ab50); 0x16d4b00 (stored by
 * FUN_00f9ab50), slot 1 (0x13e44c0) the deleting destructor calling
 * FUN_013e1850 before operator delete. One body for the 5 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object013e1850; /* derived name */

void FUN_013e1850(Object013e1850 *self); /* derived name */

void FUN_013e44b0(Object013e1850 *self) /* derived name */
{
    FUN_013e1850(self);
}
