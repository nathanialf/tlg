/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00ced570, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b9958 (stored by FUN_00cef2f0),
 * slot 1 (0x13b2e70) the deleting destructor calling FUN_00ced570 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00ced570; /* derived name */

void FUN_00ced570(Object00ced570 *self); /* derived name */

void FUN_013b2e60(Object00ced570 *self) /* derived name */
{
    FUN_00ced570(self);
}
