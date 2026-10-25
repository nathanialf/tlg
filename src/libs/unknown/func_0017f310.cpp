/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkMemoryResourceHandle's vtable (address point
 * 0x16a6280) returns the class of the object it holds. */
const hkClass *hkMemoryResourceHandle::FUN_0017f310() const /* derived name */
{
    return FUN_000902f0(&variant);
}
