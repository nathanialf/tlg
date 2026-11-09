/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013b3ae0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d20e0 (stored by FUN_00d0ae60
 * FUN_013b3ae0), slot 1 (0x13b3ac0) the deleting destructor calling
 * FUN_013b3ae0 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013b3ae0; /* derived name */

void FUN_013b3ae0(Object013b3ae0 *self); /* derived name */

void FUN_013b3ab0(Object013b3ae0 *self) /* derived name */
{
    FUN_013b3ae0(self);
}
