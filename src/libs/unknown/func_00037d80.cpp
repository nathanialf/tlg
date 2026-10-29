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

/* derived name: slot 32: the mask's slot 4 asked, the mutation signal
 * fired with 2, the mask's answer returned. */
bool hknpMaskedShape::FUN_00037dd0()
{
    const bool result = mask->FUN_000381d0();
    mutationSignals.shapeMutated.fire(2);
    return result;
}
