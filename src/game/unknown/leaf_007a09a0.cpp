/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00774560, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16adc50 (stored by FUN_007a0840),
 * slot 1 (0x7a09b0) the deleting destructor calling FUN_00774560 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object00774560; /* derived name */

void FUN_00774560(Object00774560 *self); /* derived name */

void FUN_007a09a0(Object00774560 *self) /* derived name */
{
    FUN_00774560(self);
}
