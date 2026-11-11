/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: a callback whose address FUN_01342d50 takes (lea at
 * 0x1342dc1): when the record at +0x28 is set, copies its two vectors at
 * +0x120 and +0x140 to +0x30 and +0x40; returns 1. The types are not traced. */
struct Source00422b60 { /* derived name */
    u8 unknown0[0x120];
    Vec4 unknown120;
    u8 unknown130[0x10];
    Vec4 unknown140;
};

struct Object00422b60 { /* derived name */
    u8 unknown0[0x28];
    const Source00422b60 *unknown28;
    Vec4 unknown30;
    Vec4 unknown40;
};

int FUN_00422b60(Object00422b60 *self) /* derived name */
{
    if (const Source00422b60 *source = self->unknown28) {
        self->unknown30 = source->unknown120;
        self->unknown40 = source->unknown140;
    }
    return 1;
}
