/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00d237d0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ae900 (stored by no constructor
 * listed); 0x16d18b0 (stored by FUN_00ccaa30); 0x16d2ed0 (stored by
 * FUN_00e82bb0), slot 1 (0x81b380) the deleting destructor calling
 * FUN_00d237d0 before operator delete. One body for the 3 vtables. Written as
 * a free function on the base record until the base destructor's row is named
 * (a class form needs its D2 symbol). */
struct Object00d237d0; /* derived name */

void FUN_00d237d0(Object00d237d0 *self); /* derived name */

void FUN_0081b370(Object00d237d0 *self) /* derived name */
{
    FUN_00d237d0(self);
}
