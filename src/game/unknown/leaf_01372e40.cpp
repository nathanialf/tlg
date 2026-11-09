/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01372e50, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16cc378 (stored by FUN_00886dc0
 * FUN_0088b4e0 FUN_008a4490 FUN_01372e50), slot 1 (0x1373220) the deleting
 * destructor calling FUN_01372e50 before operator delete. Written as a free
 * function on the record until the destructor's row is named (a class form
 * needs its D2 symbol). */
struct Object01372e50; /* derived name */

void FUN_01372e50(Object01372e50 *self); /* derived name */

void FUN_01372e40(Object01372e50 *self) /* derived name */
{
    FUN_01372e50(self);
}
