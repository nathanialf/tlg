/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00c324b0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16b9cb0 (stored by FUN_001afd70),
 * slot 1 (0xc32920) the deleting destructor calling FUN_00c324b0 before
 * operator delete. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00c324b0; /* derived name */

void FUN_00c324b0(Object00c324b0 *self); /* derived name */

void FUN_013b3a80(Object00c324b0 *self) /* derived name */
{
    FUN_00c324b0(self);
}
