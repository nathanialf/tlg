/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16cee20 (its pointer at
 * 0x16cee38): takes the given size from the buffer at +0x8: null without a
 * buffer or when the used size at +0x14 plus the request passes the capacity at
 * +0x10, else the buffer's address at the used size, which it then advances.
 * Class and method unknown. */
struct Object01393620 { /* derived name */
    u8 unknown0[0x8];
    u8 *unknown8;
    int unknown10;
    int unknown14;
};

void *FUN_01393620(Object01393620 *self, int size) /* derived name */
{
    if (!self->unknown8) {
        return 0;
    }
    int used = self->unknown14 + size;
    if (used > self->unknown10) {
        return 0;
    }
    u8 *block = self->unknown8 + self->unknown14;
    self->unknown14 = used;
    return block;
}
