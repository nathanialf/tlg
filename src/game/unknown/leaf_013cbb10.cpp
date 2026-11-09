/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013671a0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16be190 (stored by FUN_00e8ed90);
 * 0x16cb7d0 (stored by FUN_013671a0); 0x16d1930 (stored by FUN_00ccafe0);
 * 0x16d1cf8 (stored by FUN_00cd7490), slot 1 (0x13cbb20) the deleting
 * destructor calling FUN_013671a0 before operator delete. One body for the 4
 * vtables. Written as a free function on the record until the destructor's row
 * is named (a class form needs its D2 symbol). */
struct Object013671a0; /* derived name */

void FUN_013671a0(Object013671a0 *self); /* derived name */

void FUN_013cbb10(Object013671a0 *self) /* derived name */
{
    FUN_013671a0(self);
}
