/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013eb8e0, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16c0938 (stored by FUN_00fe2710);
 * 0x16d4de8 (stored by FUN_00fe2710 FUN_013eb8e0), slot 1 (0x13ebcd0) the
 * deleting destructor calling FUN_013eb8e0 before operator delete. One body
 * for the 2 vtables. Written as a free function on the record until the
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object013eb8e0; /* derived name */

void FUN_013eb8e0(Object013eb8e0 *self); /* derived name */

void FUN_013eb8d0(Object013eb8e0 *self) /* derived name */
{
    FUN_013eb8e0(self);
}
