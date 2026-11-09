/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00ccfd00, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16d1a08 (stored by no constructor
 * listed); 0x16d1a78 (stored by FUN_00ccfe60); 0x16d1bc8 (stored by
 * FUN_00cd5380); 0x16d31a0 (stored by FUN_00e903d0), slot 1 (0x13af050) the
 * deleting destructor calling FUN_00ccfd00 before operator delete. One body
 * for the 4 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00ccfd00; /* derived name */

void FUN_00ccfd00(Object00ccfd00 *self); /* derived name */

void FUN_013af040(Object00ccfd00 *self) /* derived name */
{
    FUN_00ccfd00(self);
}
