/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00eb2af0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16be710 (stored by no constructor
 * listed); 0x16be7c0 (stored by no constructor listed); 0x16be950 (stored by
 * no constructor listed), slot 1 (0x13cc9f0) the deleting destructor calling
 * FUN_00eb2af0 before operator delete. One body for the 3 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object00eb2af0; /* derived name */

void FUN_00eb2af0(Object00eb2af0 *self); /* derived name */

void FUN_013cc9e0(Object00eb2af0 *self) /* derived name */
{
    FUN_00eb2af0(self);
}
