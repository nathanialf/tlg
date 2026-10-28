/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the suffix test of a string buffer, its characters from
 * the end compared with the suffix's (cookbook 111's loop). */
int hkStringBuf::FUN_00011870(const char *suffix) const
{
    const int suffixLength = FUN_00017fe0(suffix);
    if (suffixLength > getLength()) {
        return false;
    }
    const int start = getLength() - suffixLength;
    int i = 0;
    while (i < suffixLength) {
        const char c = string.data[start + i];
        if (c != suffix[i++]) {
            return false;
        }
    }
    return true;
}
