/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013752a0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16cc5b8 (stored by FUN_009232e0
 * FUN_013752a0), slot 1 (0x1375570) the deleting destructor calling
 * FUN_013752a0 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013752a0; /* derived name */

void FUN_013752a0(Object013752a0 *self); /* derived name */

void FUN_01375290(Object013752a0 *self) /* derived name */
{
    FUN_013752a0(self);
}
