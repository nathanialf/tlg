/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01368710, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16cb718 (stored by FUN_007204d0);
 * 0x16cb7b0 (stored by FUN_007204d0 FUN_01368710), slot 1 (0x1369c80) the
 * deleting destructor calling FUN_01368710 before operator delete. One body
 * for the 2 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object01368710; /* derived name */

void FUN_01368710(Object01368710 *self); /* derived name */

void FUN_01369c70(Object01368710 *self) /* derived name */
{
    FUN_01368710(self);
}
