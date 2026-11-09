/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00cf7fb0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16d1ee8 (stored by FUN_00cf8300);
 * 0x16d1f28 (stored by FUN_00cf8af0); 0x16d1fe8 (stored by FUN_00cfa710);
 * 0x16d20a0 (stored by FUN_00cfe310), slot 1 (0xcf8100) the deleting
 * destructor calling FUN_00cf7fb0 before operator delete. One body for the 4
 * vtables. Written as a free function on the record until the destructor's row
 * is named (a class form needs its D2 symbol). */
struct Object00cf7fb0; /* derived name */

void FUN_00cf7fb0(Object00cf7fb0 *self); /* derived name */

void FUN_013b34e0(Object00cf7fb0 *self) /* derived name */
{
    FUN_00cf7fb0(self);
}
