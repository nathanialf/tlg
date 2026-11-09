/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0083df00, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b65f8 (stored by FUN_00b4c8b0),
 * slot 1 (0xb4ca30) the deleting destructor calling FUN_0083df00 before
 * operator delete. Written as a free function on the base record until the
 * base destructor's row is named (a class form needs its D2 symbol). */
struct Object0083df00; /* derived name */

void FUN_0083df00(Object0083df00 *self); /* derived name */

void FUN_00b4ca20(Object0083df00 *self) /* derived name */
{
    FUN_0083df00(self);
}
