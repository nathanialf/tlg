/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 54 of the vtable at 0x16c7d80: when its argument has
 * an object at +0x10, sets that object's vector at +0xf0 to all ones (the
 * constant at 0x1540fa0); returns 1. The object (this) is not read. Class and
 * method unknown. */
struct Member00b406b0 { /* derived name */
    u8 unknown0[0xf0];
    Vec4 unknownf0;
};

struct Record00b406b0 { /* derived name */
    u8 unknown0[0x10];
    Member00b406b0 *unknown10;
};

int FUN_00b406b0(void *, Record00b406b0 *record) /* derived name */
{
    if (record->unknown10) {
        record->unknown10->unknownf0 = _mm_set1_ps(1.0f);
    }
    return 1;
}
