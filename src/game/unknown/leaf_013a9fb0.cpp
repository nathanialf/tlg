/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00d30550, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d1578 (stored by FUN_00c68720),
 * slot 1 (0x13a9fc0) the deleting destructor calling FUN_00d30550 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00d30550; /* derived name */

void FUN_00d30550(Object00d30550 *self); /* derived name */

void FUN_013a9fb0(Object00d30550 *self) /* derived name */
{
    FUN_00d30550(self);
}
