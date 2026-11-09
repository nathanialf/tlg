/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013a1e00, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16d05f8 (stored by FUN_013a1e00),
 * slot 1 (0x13a2160) the deleting destructor calling FUN_013a1e00 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object013a1e00; /* derived name */

void FUN_013a1e00(Object013a1e00 *self); /* derived name */

void FUN_013a1df0(Object013a1e00 *self) /* derived name */
{
    FUN_013a1e00(self);
}
