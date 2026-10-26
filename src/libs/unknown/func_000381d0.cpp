/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 4 of hknpMaskedShape::MaskWrapper's vtable (address
 * point 0x1693bb0): has the masked shape apply its mask (its slot 32) and
 * returns the mask's answer. */
bool hknpMaskedShape::MaskWrapper::FUN_000381d0()
{
    return maskedShape->FUN_00037dd0();
}
