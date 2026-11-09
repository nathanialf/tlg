/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013e1b30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ca568 (stored by FUN_013e1b30
 * FUN_013e30b0); 0x16d4630 (stored by FUN_00fbaf70); 0x16d4688 (stored by
 * FUN_00fbaf70); 0x16d46e0 (stored by FUN_00fbadf0); 0x16d4738 (stored by
 * FUN_00fbadf0); 0x16d4790 (stored by FUN_00fbac70); 0x16d47e8 (stored by
 * FUN_00fbac70); 0x16d4840 (stored by FUN_00fbaaf0); 0x16d4898 (stored by
 * FUN_00fbaaf0), slot 1 (0x13e4990) the deleting destructor calling
 * FUN_013e1b30 before operator delete. One body for the 9 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object013e1b30; /* derived name */

void FUN_013e1b30(Object013e1b30 *self); /* derived name */

void FUN_013e4980(Object013e1b30 *self) /* derived name */
{
    FUN_013e1b30(self);
}
