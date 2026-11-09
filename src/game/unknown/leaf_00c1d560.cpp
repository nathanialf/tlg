/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00c1b7f0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b81d0 (stored by FUN_00c1ce60),
 * slot 1 (0xc1d570) the deleting destructor calling FUN_00c1b7f0 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object00c1b7f0; /* derived name */

void FUN_00c1b7f0(Object00c1b7f0 *self); /* derived name */

void FUN_00c1d560(Object00c1b7f0 *self) /* derived name */
{
    FUN_00c1b7f0(self);
}
