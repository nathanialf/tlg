/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class derived from the one whose
 * destructor is FUN_00b42e30, its own body empty, so the base destructor runs
 * as a tail call; slot 0 of the vtables at 0x16cf888 (stored by no constructor
 * listed); 0x16cf9f8 (stored by FUN_00b40f10); 0x16cfb98 (stored by
 * FUN_00b40f10); 0x16cfd08 (stored by no constructor listed); 0x16cfda8
 * (stored by no constructor listed); 0x16cfe48 (stored by no constructor
 * listed), slot 1 (0x139b3b0) the deleting destructor calling FUN_00b42e30
 * before operator delete. One body for the 6 vtables. Written as a free
 * function on the record until the destructor's row is named (a class form
 * needs its D2 symbol). */
struct Object00b42e30; /* derived name */

void FUN_00b42e30(Object00b42e30 *self); /* derived name */

void FUN_0139b3a0(Object00b42e30 *self) /* derived name */
{
    FUN_00b42e30(self);
}
