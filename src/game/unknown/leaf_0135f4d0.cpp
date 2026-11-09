/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0135e680, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16cb318 (stored by FUN_00615670
 * FUN_007204d0 FUN_0135e680); 0x16cb358 (stored by FUN_00615670 FUN_007204d0),
 * slot 1 (0x135f620) the deleting destructor calling FUN_0135e680 before
 * operator delete. One body for the 2 vtables. Written as a free function on
 * the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0135e680; /* derived name */

void FUN_0135e680(Object0135e680 *self); /* derived name */

void FUN_0135f4d0(Object0135e680 *self) /* derived name */
{
    FUN_0135e680(self);
}
