/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0147d190, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ca8b0 (stored by FUN_0122be10
 * FUN_0147d190); 0x16d6bf0 (stored by FUN_0122be10); 0x16d6c48 (stored by
 * FUN_0122be10); 0x16d73e8 (stored by FUN_0122be10); 0x16d7440 (stored by
 * FUN_0122be10), slot 1 (0x147eef0) the deleting destructor calling
 * FUN_0147d190 before operator delete. One body for the 5 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object0147d190; /* derived name */

void FUN_0147d190(Object0147d190 *self); /* derived name */

void FUN_0147eee0(Object0147d190 *self) /* derived name */
{
    FUN_0147d190(self);
}
