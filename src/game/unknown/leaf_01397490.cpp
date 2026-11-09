/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00b40050, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b5ae8 (stored by FUN_00b3f8e0),
 * slot 1 (0x13974a0) the deleting destructor calling FUN_00b40050 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00b40050; /* derived name */

void FUN_00b40050(Object00b40050 *self); /* derived name */

void FUN_01397490(Object00b40050 *self) /* derived name */
{
    FUN_00b40050(self);
}
