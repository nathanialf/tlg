/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01370f10, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtable at 0x16af078 (stored by FUN_0085e360
 * FUN_0085e950 FUN_01370f10), slot 1 (0x1371580) the deleting destructor
 * calling FUN_01370f10 before operator delete. Written as a free function on
 * the record until the destructor's row is named (a class form needs its D2
 * symbol). */
struct Object01370f10; /* derived name */

void FUN_01370f10(Object01370f10 *self); /* derived name */

void FUN_01371570(Object01370f10 *self) /* derived name */
{
    FUN_01370f10(self);
}
