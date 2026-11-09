/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00204320, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16ac868 (stored by FUN_007609e0),
 * slot 1 (0x760bd0) the deleting destructor calling FUN_00204320 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object00204320; /* derived name */

void FUN_00204320(Object00204320 *self); /* derived name */

void FUN_00760bc0(Object00204320 *self) /* derived name */
{
    FUN_00204320(self);
}
