/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00d2fc50): when the
 * pointer at +0x8 of its second argument equals the one at +0x40 of the first,
 * stores the first at +0x0 of the second and returns 0, else returns 1. The
 * types are not traced. */
struct Object00d302d0 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40;
};

struct Search00d302d0 { /* derived name */
    Object00d302d0 *unknown0;
    void *unknown8;
};

int FUN_00d302d0(Object00d302d0 *self, Search00d302d0 *search) /* derived name */
{
    if (search->unknown8 != self->unknown40) {
        return 1;
    }
    search->unknown0 = self;
    return 0;
}
