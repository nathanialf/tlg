/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0137e6e0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16c7b78 (stored by FUN_00958460
 * FUN_0137e6e0), slot 1 (0x137e240) the deleting destructor calling
 * FUN_0137e6e0 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0137e6e0; /* derived name */

void FUN_0137e6e0(Object0137e6e0 *self); /* derived name */

void FUN_0137e230(Object0137e6e0 *self) /* derived name */
{
    FUN_0137e6e0(self);
}
