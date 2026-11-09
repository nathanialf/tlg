/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0130acb0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16d7ed8 (stored by FUN_012fed00);
 * 0x16d7f00 (stored by FUN_01304c20); 0x16d7fa8 (stored by FUN_0131e5d0);
 * 0x16d7fd0 (stored by FUN_0131f450); 0x16d8028 (stored by FUN_01320fe0), slot
 * 1 (0x1496900) the deleting destructor calling FUN_0130acb0 before operator
 * delete. One body for the 5 vtables. Written as a free function on the record
 * until the destructor's row is named (a class form needs its D2 symbol). */
struct Object0130acb0; /* derived name */

void FUN_0130acb0(Object0130acb0 *self); /* derived name */

void FUN_014968f0(Object0130acb0 *self) /* derived name */
{
    FUN_0130acb0(self);
}
