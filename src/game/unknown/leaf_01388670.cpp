/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01388680, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16ce038 (stored by FUN_00a036a0
 * FUN_01388680), slot 1 (0x1388750) the deleting destructor calling
 * FUN_01388680 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01388680; /* derived name */

void FUN_01388680(Object01388680 *self); /* derived name */

void FUN_01388670(Object01388680 *self) /* derived name */
{
    FUN_01388680(self);
}
