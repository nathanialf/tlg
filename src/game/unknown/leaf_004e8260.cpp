/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_slot9.h"

/* derived names: slot 9 of the vtable at 0x16aa6e0 (stored by FUN_004e7e20 FUN_004e8070; the
 * class named for the vtable): runs FUN_0042d4e0 on the object, then drops
 * the name at +0x1c4 and sets the int after it to -1. */
struct Object016aa6e0 : Object0042d4e0 /* derived name */
{
    u8 unknown0[0x1c4];
    Name name1c4;   /* +0x1c4 */
    int unknown1c8; /* +0x1c8 */
};

void FUN_004e8260(Object016aa6e0 *self) /* derived name */
{
    FUN_0042d4e0(self);
    self->name1c4.release();
    self->unknown1c8 = -1;
}
