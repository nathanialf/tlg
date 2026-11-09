/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00818d10, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b4dc0 (stored by FUN_00b1b370),
 * slot 1 (0xb1b580) the deleting destructor calling FUN_00818d10 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object00818d10; /* derived name */

void FUN_00818d10(Object00818d10 *self); /* derived name */

void FUN_00b1b570(Object00818d10 *self) /* derived name */
{
    FUN_00818d10(self);
}
