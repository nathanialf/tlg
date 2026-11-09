/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0147ec30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16caa98 (stored by FUN_0122be10
 * FUN_0147ec30), slot 1 (0x147ec10) the deleting destructor calling
 * FUN_0147ec30 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0147ec30; /* derived name */

void FUN_0147ec30(Object0147ec30 *self); /* derived name */

void FUN_0147ec00(Object0147ec30 *self) /* derived name */
{
    FUN_0147ec30(self);
}
