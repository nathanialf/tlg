/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01481660, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16c2a68 (stored by FUN_0124f080);
 * 0x16d74e8 (stored by FUN_0124f080 FUN_01481660), slot 1 (0x1481a50) the
 * deleting destructor calling FUN_01481660 before operator delete. One body
 * for the 2 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object01481660; /* derived name */

void FUN_01481660(Object01481660 *self); /* derived name */

void FUN_01481650(Object01481660 *self) /* derived name */
{
    FUN_01481660(self);
}
