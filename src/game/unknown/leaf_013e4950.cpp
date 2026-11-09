/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_013e2310, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ca768 (stored by FUN_013e2310
 * FUN_013e34f0); 0x16d4370 (stored by FUN_00f9ab50); 0x16d43c8 (stored by
 * FUN_00f9ab50); 0x16d4420 (stored by FUN_00f9ab50); 0x16d4478 (stored by
 * FUN_00f9ab50); 0x16d44d0 (stored by FUN_00fbb270); 0x16d4528 (stored by
 * FUN_00fbb270); 0x16d4580 (stored by FUN_00fbb0f0); 0x16d45d8 (stored by
 * FUN_00fbb0f0), slot 1 (0x13e4960) the deleting destructor calling
 * FUN_013e2310 before operator delete. One body for the 9 vtables. Written as
 * a free function on the record until the destructor's row is named (a class
 * form needs its D2 symbol). */
struct Object013e2310; /* derived name */

void FUN_013e2310(Object013e2310 *self); /* derived name */

void FUN_013e4950(Object013e2310 *self) /* derived name */
{
    FUN_013e2310(self);
}
