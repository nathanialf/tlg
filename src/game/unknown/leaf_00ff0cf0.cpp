/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 4 of the vtables at 0x16c0588: returns the two
 * vectors of the entry the index selects in the table the object points to at
 * +0x8 (32-byte entries after a 32-byte head). Class and method unknown. */
struct Pair00ff0cf0 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
};

struct Table00ff0cf0 { /* derived name */
    u8 unknown0[0x20];
    Pair00ff0cf0 unknown20[1];

    const Pair00ff0cf0 &at(int index) const
    {
        return unknown20[index];
    } /* derived name */
};

struct Object00ff0cf0 { /* derived name */
    u8 unknown0[0x8];
    Table00ff0cf0 *unknown8;
};

/* the two vectors are copied one by one (returned as one aggregate assignment the copy is a single 32-byte move) */
Pair00ff0cf0 FUN_00ff0cf0(const Object00ff0cf0 *self, int index) /* derived name */
{
    const Pair00ff0cf0 &entry = self->unknown8->at(index);
    Pair00ff0cf0 result;
    result.unknown0 = entry.unknown0;
    result.unknown10 = entry.unknown10;
    return result;
}
