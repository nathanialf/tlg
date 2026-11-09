/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01397620, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16b5a40 (stored by FUN_00b3ec10);
 * 0x16b5c48 (stored by FUN_00b404d0 FUN_01397620), slot 1 (0x1397aa0) the
 * deleting destructor calling FUN_01397620 before operator delete. One body
 * for the 2 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object01397620; /* derived name */

void FUN_01397620(Object01397620 *self); /* derived name */

void FUN_01397a90(Object01397620 *self) /* derived name */
{
    FUN_01397620(self);
}
