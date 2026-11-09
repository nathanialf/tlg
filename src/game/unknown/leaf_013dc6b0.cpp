/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013dc6c0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d4b58 (stored by FUN_00f96270
 * FUN_013dc6c0), slot 1 (0x13e02d0) the deleting destructor calling
 * FUN_013dc6c0 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013dc6c0; /* derived name */

void FUN_013dc6c0(Object013dc6c0 *self); /* derived name */

void FUN_013dc6b0(Object013dc6c0 *self) /* derived name */
{
    FUN_013dc6c0(self);
}
