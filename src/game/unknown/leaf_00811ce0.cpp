/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0082f900, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16ae4d0 (stored by FUN_00811b30),
 * slot 1 (0x811cf0) the deleting destructor calling FUN_0082f900 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object0082f900; /* derived name */

void FUN_0082f900(Object0082f900 *self); /* derived name */

void FUN_00811ce0(Object0082f900 *self) /* derived name */
{
    FUN_0082f900(self);
}
