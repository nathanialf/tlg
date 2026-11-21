/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_slot9.h"

/* derived names: slot 9 of the vtable at 0x16aad98 (stored by FUN_00509f80 FUN_0050a0e0; the
 * class named for the vtable): runs FUN_0042d4e0 on the object, then empties
 * the names at +0x110 and +0x114 and clears the three ints after them. */
struct Object016aad98 : Object0042d4e0 /* derived name */
{
    u8 unknown0[0x110];
    Name name110; /* +0x110 */
    Name name114; /* +0x114 */
    u8 unknown118[4];
    int unknown11c; /* +0x11c */
    int unknown120; /* +0x120 */
    int unknown124; /* +0x124 */
};

void FUN_0050a220(Object016aad98 *self) /* derived name */
{
    FUN_0042d4e0(self);
    self->name110 = Name();
    self->name114 = Name();
    self->unknown11c = 0;
    self->unknown120 = 0;
    self->unknown124 = 0;
}
