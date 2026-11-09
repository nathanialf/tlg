/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0147d450, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16caa48 (stored by FUN_0147d450
 * FUN_0147ddb0); 0x16d70d0 (stored by FUN_0122be10); 0x16d7128 (stored by
 * FUN_0122be10); 0x16d7180 (stored by FUN_0122be10); 0x16d71d8 (stored by
 * FUN_0122be10); 0x16d7230 (stored by FUN_0122be10); 0x16d7288 (stored by
 * FUN_0122be10); 0x16d72e0 (stored by FUN_0122be10); 0x16d7338 (stored by
 * FUN_0122be10), slot 1 (0x147f060) the deleting destructor calling
 * FUN_0147d450 before operator delete. One body for the 9 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object0147d450; /* derived name */

void FUN_0147d450(Object0147d450 *self); /* derived name */

void FUN_0147f050(Object0147d450 *self) /* derived name */
{
    FUN_0147d450(self);
}
