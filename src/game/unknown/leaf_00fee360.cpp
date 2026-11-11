/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 4 of the vtables at 0x16c0498 and six more: returns the two
 * vectors of the entry the index selects in the table the object points to at
 * +0x8 (32-byte entries after a 32-byte head). Class and method unknown. */
struct Pair00fee360 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
};

struct Table00fee360 { /* derived name */
    u8 unknown0[0x20];
    Pair00fee360 unknown20[1];
};

struct Object00fee360 { /* derived name */
    u8 unknown0[0x8];
    Table00fee360 *unknown8;
};

// NONMATCHING: greedy's assignment: the base gives the table pointer rax and the scaled index rcx (`[rax + rcx + 0x20]`), the compile rcx and rax; every instruction else equal. Returned as one aggregate, the copy is a single 32-byte ymm move (the base copies the two vectors)
Pair00fee360 FUN_00fee360(const Object00fee360 *self, int index) /* derived name */
{
    const Pair00fee360 &entry = self->unknown8->unknown20[index];
    Pair00fee360 result;
    result.unknown0 = entry.unknown0;
    result.unknown10 = entry.unknown10;
    return result;
}
