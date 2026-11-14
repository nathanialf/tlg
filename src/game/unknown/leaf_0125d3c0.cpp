/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 4 of the vtables at 0x16c2730: returns the two
 * vectors of the entry the index selects in the table the object points to at
 * +0x8 (32-byte entries after a 32-byte head). Class and method unknown. */
struct Pair0125d3c0 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
};

struct Table0125d3c0 { /* derived name */
    u8 unknown0[0x20];
    Pair0125d3c0 unknown20[1];

    const Pair0125d3c0 &at(int index) const
    {
        return unknown20[index];
    } /* derived name */
};

struct Object0125d3c0 { /* derived name */
    u8 unknown0[0x8];
    Table0125d3c0 *unknown8;
};

/* the two vectors are copied one by one (returned as one aggregate assignment the copy is a single 32-byte move) */
Pair0125d3c0 FUN_0125d3c0(const Object0125d3c0 *self, int index) /* derived name */
{
    const Pair0125d3c0 &entry = self->unknown8->at(index);
    Pair0125d3c0 result;
    result.unknown0 = entry.unknown0;
    result.unknown10 = entry.unknown10;
    return result;
}
