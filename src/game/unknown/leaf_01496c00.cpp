/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0131fdb0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16d7f58 (stored by FUN_01306590);
 * 0x16d7f80 (stored by FUN_01309e50), slot 1 (0x131fe80) the deleting
 * destructor calling FUN_0131fdb0 before operator delete. One body for the 2
 * vtables. Written as a free function on the record until the destructor's row
 * is named (a class form needs its D2 symbol). */
struct Object0131fdb0; /* derived name */

void FUN_0131fdb0(Object0131fdb0 *self); /* derived name */

void FUN_01496c00(Object0131fdb0 *self) /* derived name */
{
    FUN_0131fdb0(self);
}
