/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0139dbd0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d01a8 (stored by FUN_00b8c400
 * FUN_0139dbd0), slot 1 (0x139ddc0) the deleting destructor calling
 * FUN_0139dbd0 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0139dbd0; /* derived name */

void FUN_0139dbd0(Object0139dbd0 *self); /* derived name */

void FUN_0139ddb0(Object0139dbd0 *self) /* derived name */
{
    FUN_0139dbd0(self);
}
