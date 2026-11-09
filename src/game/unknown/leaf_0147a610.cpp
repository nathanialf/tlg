/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0147a620, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d7498 (stored by FUN_01227740
 * FUN_0147a620), slot 1 (0x147bc10) the deleting destructor calling
 * FUN_0147a620 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object0147a620; /* derived name */

void FUN_0147a620(Object0147a620 *self); /* derived name */

void FUN_0147a610(Object0147a620 *self) /* derived name */
{
    FUN_0147a620(self);
}
