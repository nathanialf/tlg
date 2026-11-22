/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 7 of the vtable at 0x16b6a70 (slot 8 is FUN_00b56250):
 * gives each of the records the array at +0x38 holds (the count at +0x40)
 * the object's name at +0xc as its name at +0x48 and the object as its
 * pointer at +0x40, the record read again after the name's assignment.
 * Class and method unknown. */
struct Object00b561a0; /* derived name */

struct Item00b561a0 { /* derived name */
    u8 unknown0[0x40];
    Object00b561a0 *owner; /* +0x40 */
    Name name;             /* +0x48 */
};

struct Object00b561a0 { /* derived name */

    Item00b561a0 *item(int index) const
    {
        return items[index];
    }

    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x28];
    Item00b561a0 **items; /* +0x38 */
    u32 count;            /* +0x40 */
};

void FUN_00b561a0(Object00b561a0 *self) /* derived name */
{
    for (u32 i = 0; i < self->count; ++i) {
        self->item(i)->name = self->name;
        self->item(i)->owner = self;
    }
}
