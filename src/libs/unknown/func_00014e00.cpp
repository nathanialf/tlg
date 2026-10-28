/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the items searched in order for the name, compared
 * without case (the loop tested at the top, as the value's search). */
hkResult hkClassEnum::FUN_00014e00(const char *itemName, int *valueOut) const
{
    int i = -1;
    while (++i < numItems) {
        if (hkString::FUN_00017f60(itemName, items[i].name) == 0) {
            *valueOut = items[i].value;
            return HK_SUCCESS;
        }
    }
    return HK_FAILURE;
}
