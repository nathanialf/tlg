/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_slot9.h"

/* derived names: slot 9 of the vtable at 0x16aa5d8 (stored by FUN_004e1910 FUN_004e1d20; the
 * class named for the vtable): runs FUN_0042d4e0 on the object, then drops
 * the name at +0x224 and sets the int after it to -1. */
struct Object016aa5d8 : Object0042d4e0 /* derived name */
{
    u8 unknown0[0x224];
    Name name224;   /* +0x224 */
    int unknown228; /* +0x228 */
};

void FUN_004e22d0(Object016aa5d8 *self) /* derived name */
{
    FUN_0042d4e0(self);
    self->name224.release();
    self->unknown228 = -1;
}
