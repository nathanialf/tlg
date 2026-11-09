/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01353b30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16cae48 (stored by FUN_013534f0
 * FUN_01353b30), slot 1 (0x1353b10) the deleting destructor calling
 * FUN_01353b30 before operator delete. Written as a free function on the
 * record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01353b30; /* derived name */

void FUN_01353b30(Object01353b30 *self); /* derived name */

void FUN_01353b00(Object01353b30 *self) /* derived name */
{
    FUN_01353b30(self);
}
