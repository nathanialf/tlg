/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0083df00, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16cd900 (stored by FUN_009b4960),
 * slot 1 (0x1383fc0) the deleting destructor calling FUN_0083df00 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object0083df00; /* derived name */

void FUN_0083df00(Object0083df00 *self); /* derived name */

void FUN_01383fb0(Object0083df00 *self) /* derived name */
{
    FUN_0083df00(self);
}
