/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16a90a8: unless the int at +0x48 is
 * set, FUN_003e4230 with its argument, the addresses of +0x20 and +0x30, the
 * words at +0xc and +0x10 or'ed, and the floats at +0x44 and +0x40, as a tail
 * call. The types are not traced. Class and method unknown. */
struct Pair003e3e00 { /* derived name */
    float x;
    float y;
};

struct Object003e3e00 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
    u32 unknown10;
    u8 unknown14[0xc];
    u8 unknown20[0x10];
    u8 unknown30[0x10];
    Pair003e3e00 unknown40;
    int unknown48;
};

void FUN_003e4230(void *target, const void *a, const void *b, u32 flags, float c,
                  float d); /* derived name */

void FUN_003e3e00(const Object003e3e00 *self, void *target) /* derived name */
{
    if (self->unknown48) {
        return;
    }
    Pair003e3e00 pair = self->unknown40;
    FUN_003e4230(target, self->unknown20, self->unknown30, self->unknownc | self->unknown10, pair.y,
                 pair.x);
}
