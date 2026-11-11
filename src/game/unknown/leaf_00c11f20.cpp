/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a sort comparison whose address FUN_00c0fb30 takes (lea at
 * 0xc100b7): ascending by the float at +0x14, then descending by the unsigned
 * int at +0x10 (-1, 0 or 1). The record type is not traced. */
struct Entry00c11f20 { /* derived name */
    u8 unknown0[0x10];
    u32 unknown10;
    float unknown14;
};

int FUN_00c11f20(const void *a, const void *b) /* derived name */
{
    const Entry00c11f20 *left = static_cast<const Entry00c11f20 *>(a);
    const Entry00c11f20 *right = static_cast<const Entry00c11f20 *>(b);
    if (left->unknown14 >= right->unknown14) {
        if (left->unknown14 > right->unknown14) {
            return 1;
        }
        if (left->unknown10 > right->unknown10) {
            return -1;
        }
        return left->unknown10 < right->unknown10;
    }
    return -1;
}
