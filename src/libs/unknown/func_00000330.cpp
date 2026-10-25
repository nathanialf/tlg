/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkMonitorStreamStringMap::StringMap's
 * type info (0x57af4d0; hkxEnum::Item's at 0x57c7010, the same layout,
 * holds the same body): destroy the entry in place, which destroys its
 * hkStringPtr at +8. */
void FUN_00000330(void *object) /* derived name */
{
    FUN_0000e5d0(&static_cast<hkMonitorStreamStringMapStringMap *>(object)->string);
}
