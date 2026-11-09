/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0147d810, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16cab48 (stored by FUN_0147d810
 * FUN_0147e1f0); 0x16d6e10 (stored by FUN_0122be10); 0x16d6e68 (stored by
 * FUN_0122be10); 0x16d6ec0 (stored by FUN_0122be10); 0x16d6f18 (stored by
 * FUN_0122be10); 0x16d6f70 (stored by FUN_0122be10); 0x16d6fc8 (stored by
 * FUN_0122be10); 0x16d7020 (stored by FUN_0122be10); 0x16d7078 (stored by
 * FUN_0122be10), slot 1 (0x147f030) the deleting destructor calling
 * FUN_0147d810 before operator delete. One body for the 9 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object0147d810; /* derived name */

void FUN_0147d810(Object0147d810 *self); /* derived name */

void FUN_0147f020(Object0147d810 *self) /* derived name */
{
    FUN_0147d810(self);
}
