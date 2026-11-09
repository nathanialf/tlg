/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0134ae30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16b9a90 (stored by FUN_00cf5710);
 * 0x16c73a8 (stored by FUN_001bd010 FUN_002370b0 FUN_002aa7b0 FUN_00537dd0
 * FUN_005ccd60 FUN_005fb1d0 FUN_0069d690 FUN_0077c7f0 FUN_007b3320
 * FUN_00830fb0 FUN_00840f90 FUN_00909420 FUN_0091bb60 FUN_00925b30
 * FUN_0092ddb0 FUN_00953d00 FUN_00a2b8c0 FUN_00a31aa0 FUN_00ad9d20
 * FUN_00b774e0 FUN_00bf0510 FUN_00bf1e30 FUN_00bf5f90 FUN_00c15920
 * FUN_00c7aee0 FUN_00ca4420 FUN_00cd0750 FUN_00d15970 FUN_00d1ffc0
 * FUN_00d57330 FUN_00dfe9a0 FUN_00e03660 FUN_00e10cd0 FUN_00e82e80
 * FUN_011004c0 FUN_0134ae30), slot 1 (0xcf5c30) the deleting destructor
 * calling FUN_0134ae30 before operator delete. One body for the 2 vtables.
 * Written as a free function on the base record until the base destructor's
 * row is named (a class form needs its D2 symbol). */
struct Object0134ae30; /* derived name */

void FUN_0134ae30(Object0134ae30 *self); /* derived name */

void FUN_00cf5c20(Object0134ae30 *self) /* derived name */
{
    FUN_0134ae30(self);
}
