/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkSetIntFloatPair's type info
 * (registered by 0x150c0): destroy the set in place, which frees its
 * elements. */
void hkSetIntFloatPair::FUN_00015020(void *object)
{
    static_cast<hkSetIntFloatPair *>(object)->elem.clearAndDeallocate();
}
