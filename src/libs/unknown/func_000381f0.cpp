/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hknpMaskedShape::MaskWrapper's vtable (address
 * point 0x1693bb0): asks the masked shape's mask about a key (a bool
 * return keeps the call, cookbook 25). */
bool hknpMaskedShape::MaskWrapper::FUN_000381f0(u32 key) const
{
    return maskedShape->mask->FUN_000381f0(key);
}
