/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: for each 0x100-byte entry of the array at +0x50 (the count
 * at +0x58, reloaded after each store), sets or clears bit 8 of the flags
 * word at +0x38 of the object the entry's pointer at +0x40 holds, when it is
 * set, as the second argument says (leaf_009685f0.cpp's sibling, a level
 * further). The bit's meaning is not traced. */
struct Target00968820 /* derived name */
{
    u8 unknown0[0x38];
    u32 flags38; /* +0x38 */
};

struct Entry00968820 /* derived name */
{
    u8 unknown0[0x40];
    Target00968820 *unknown40; /* +0x40 */
    u8 unknown48[0xb8];
};

struct Object00968820 /* derived name */
{
    u8 unknown0[0x50];
    Entry00968820 *unknown50; /* +0x50 */
    u32 unknown58;            /* +0x58: the entry count */
};

void FUN_00968820(Object00968820 *self, int enable) /* derived name */
{
    for (u32 i = 0; i < self->unknown58; i++) {
        if (Target00968820 *target = self->unknown50[i].unknown40)
            target->flags38 = (target->flags38 & ~0x100u) | (enable != 0) << 8;
    }
}
