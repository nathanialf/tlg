/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_0137be20, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16cc6c0 (stored by FUN_009232e0
 * FUN_009240a0 FUN_0096e710 FUN_00b383d0 FUN_00b3de50 FUN_00b3f8e0
 * FUN_0137be20 FUN_01398280); 0x16cefb0 (stored by FUN_00b383d0), slot 1
 * (0x137bf70) the deleting destructor calling FUN_0137be20 before operator
 * delete. One body for the 2 vtables. Written as a free function on the record
 * until the destructor's row is named (a class form needs its D2 symbol). */
struct Object0137be20; /* derived name */

void FUN_0137be20(Object0137be20 *self); /* derived name */

void FUN_0137bf60(Object0137be20 *self) /* derived name */
{
    FUN_0137be20(self);
}
