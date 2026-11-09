/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013d8e40, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d3e10 (stored by FUN_013d8e40
 * FUN_013d93b0), slot 1 (0x13d8f80) the deleting destructor calling
 * FUN_013d8e40 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object013d8e40; /* derived name */

void FUN_013d8e40(Object013d8e40 *self); /* derived name */

void FUN_013d8e30(Object013d8e40 *self) /* derived name */
{
    FUN_013d8e40(self);
}
