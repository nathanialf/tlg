/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the items searched in order for the value (the loop tested
 * at the top, cookbook 60). */
hkResult hkClassEnum::FUN_00014dc0(int value, const char **nameOut) const
{
    int i = -1;
    while (++i < numItems) {
        if (items[i].value == value) {
            *nameOut = items[i].name;
            return HK_SUCCESS;
        }
    }
    return HK_FAILURE;
}
