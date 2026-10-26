/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of hknpMaskedShape::MaskWrapper's vtable (address
 * point 0x1693bb0): forwards a key and its flag to the masked shape's mask
 * (the bool passed on widened, cookbook 17). */
void hknpMaskedShape::MaskWrapper::FUN_000381b0(u32 key, bool enabled)
{
    maskedShape->mask->FUN_000381b0(key, enabled);
}
