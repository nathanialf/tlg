/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkMemoryResourceHandle's vtable (address point
 * 0x16a6280) returns its name, or "null" when it has none. */
const char *hkMemoryResourceHandle::FUN_0017f2d0() const
{
    const char *string = name.cString();
    return string ? string : "null";
}
