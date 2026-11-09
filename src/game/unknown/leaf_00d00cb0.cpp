/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00cbdb30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b9e38 (stored by FUN_00d00a40),
 * slot 1 (0xd00cc0) the deleting destructor calling FUN_00cbdb30 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object00cbdb30; /* derived name */

void FUN_00cbdb30(Object00cbdb30 *self); /* derived name */

void FUN_00d00cb0(Object00cbdb30 *self) /* derived name */
{
    FUN_00cbdb30(self);
}
