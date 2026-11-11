/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 10 of the vtable at 0x16d3408 (its pointer at
 * 0x16d3468): unless its 16-bit count is 0 or 0xffff, stores one less than the
 * count with 0x5c0a0000 in its upper bits at +0x4 of the record its ninth
 * argument points to; the six arguments between are not read here. The types
 * are not traced. Class and method unknown. */
struct Record013cc160 { /* derived name */
    u32 unknown0;
    u32 unknown4;
};

void FUN_013cc160(void *, u16 count, void *, void *, void *, void *, void *, void *,
                  Record013cc160 *record) /* derived name */
{
    if (count != 0 && count != 0xffff) {
        record->unknown4 = (count - 1) | 0x5c0a0000;
    }
}
