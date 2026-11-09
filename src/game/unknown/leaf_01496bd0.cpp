/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_01326b10, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16d7f28 (stored by FUN_01304dd0);
 * 0x16d7ff8 (stored by FUN_00b997d0 FUN_00b9ced0 FUN_00bbc0d0 FUN_00bc28f0
 * FUN_00bc3da0 FUN_00bd8040 FUN_00dfa850 FUN_0131f910); 0x16d8050 (stored by
 * FUN_013217d0); 0x16d8080 (stored by FUN_01324860), slot 1 (0x1496be0) the
 * deleting destructor calling FUN_01326b10 before operator delete. One body
 * for the 4 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object01326b10; /* derived name */

void FUN_01326b10(Object01326b10 *self); /* derived name */

void FUN_01496bd0(Object01326b10 *self) /* derived name */
{
    FUN_01326b10(self);
}
