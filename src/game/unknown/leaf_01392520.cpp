/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01392530, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b4d58 (stored by FUN_00b14040
 * FUN_01392530), slot 1 (0x1392600) the deleting destructor calling
 * FUN_01392530 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01392530; /* derived name */

void FUN_01392530(Object01392530 *self); /* derived name */

void FUN_01392520(Object01392530 *self) /* derived name */
{
    FUN_01392530(self);
}
