/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 31 of hknpMaskedShape's vtable (address point
 * 0x1693a90): the mask the shape owns (an allocated shape, its size in the
 * high half of +8) deleted, a new one from the core shape (its slot 20),
 * then slot 32 run on it. */
void hknpMaskedShape::FUN_00037d80()
{
    if (mask && (memSizeAndRefCount >> 16) != 0) {
        delete mask;
        mask = 0;
    }
    mask = coreShape->unknownVirtual20();
    FUN_00037dd0();
}
