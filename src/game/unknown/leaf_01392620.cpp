/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01392440, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16b4d00 (stored by FUN_01392440);
 * 0x16cecc8 (stored by FUN_00b14040); 0x16cecf8 (stored by FUN_00b14040);
 * 0x16ced28 (stored by FUN_00b14040); 0x16ced58 (stored by FUN_00b14040), slot
 * 1 (0x1392630) the deleting destructor calling FUN_01392440 before operator
 * delete. One body for the 5 vtables. Written as a free function on the record
 * until the destructor's row is named (a class form needs its D2 symbol). */
struct Object01392440; /* derived name */

void FUN_01392440(Object01392440 *self); /* derived name */

void FUN_01392620(Object01392440 *self) /* derived name */
{
    FUN_01392440(self);
}
