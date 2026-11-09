/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00bdcda0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16ce9b8 (stored by FUN_00ae88e0),
 * slot 1 (0xbdd0b0) the deleting destructor calling FUN_00bdcda0 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00bdcda0; /* derived name */

void FUN_00bdcda0(Object00bdcda0 *self); /* derived name */

void FUN_0138eab0(Object00bdcda0 *self) /* derived name */
{
    FUN_00bdcda0(self);
}
