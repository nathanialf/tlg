/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_slot9.h"

/* derived names: slot 9 of the vtable at 0x16aa4d0 (stored by FUN_004d00b0 FUN_004d05c0; the
 * class named for the vtable): runs FUN_0042d4e0 on the object, then drops
 * the name at +0x20c and sets the int after it to -1. */
struct Object016aa4d0 : Object0042d4e0 /* derived name */
{
    u8 unknown0[0x20c];
    Name name20c;   /* +0x20c */
    int unknown210; /* +0x210 */
};

void FUN_004d0d60(Object016aa4d0 *self) /* derived name */
{
    FUN_0042d4e0(self);
    self->name20c.release();
    self->unknown210 = -1;
}
