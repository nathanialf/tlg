/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16b6a70: clears the pointer at
 * +0x40 of each of the records the array at +0x38 holds (the count at +0x40).
 * Class and method unknown. */
struct Item00b56250 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40;
};

struct Object00b56250 { /* derived name */

    Item00b56250 *item(int index) const
    {
        return items[index];
    }

    u8 unknown0[0x38];
    Item00b56250 **items;
    u32 count;
};

void FUN_00b56250(Object00b56250 *self) /* derived name */
{
    for (u32 i = 0; i < self->count; ++i) {
        self->item(i)->unknown40 = 0;
    }
}
