/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01358d70, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16cb108 (stored by FUN_013589f0
 * FUN_01358d70), slot 1 (0x13595f0) the deleting destructor calling
 * FUN_01358d70 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01358d70; /* derived name */

void FUN_01358d70(Object01358d70 *self); /* derived name */

void FUN_013595e0(Object01358d70 *self) /* derived name */
{
    FUN_01358d70(self);
}
