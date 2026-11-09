/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00c55550, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16ae2c8 (stored by FUN_0080b010);
 * 0x16ba5d0 (stored by FUN_00d48d60); 0x16d0708 (stored by FUN_00c2a5d0);
 * 0x16d2608 (stored by FUN_00d768b0), slot 1 (0x80b1f0) the deleting
 * destructor calling FUN_00c55550 before operator delete. One body for the 4
 * vtables. Written as a free function on the base record until the base
 * destructor's row is named (a class form needs its D2 symbol). */
struct Object00c55550; /* derived name */

void FUN_00c55550(Object00c55550 *self); /* derived name */

void FUN_0080b1e0(Object00c55550 *self) /* derived name */
{
    FUN_00c55550(self);
}
