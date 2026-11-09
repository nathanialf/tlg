/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013e4510, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d4348 (stored by FUN_013dfef0
 * FUN_013e4510), slot 1 (0x13e44f0) the deleting destructor calling
 * FUN_013e4510 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013e4510; /* derived name */

void FUN_013e4510(Object013e4510 *self); /* derived name */

void FUN_013e44e0(Object013e4510 *self) /* derived name */
{
    FUN_013e4510(self);
}
