/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool FUN_000181c0(const char *string, const char *suffix) /* derived name */
{
    const int stringLength = strlen(string);
    const int suffixLength = strlen(suffix);
    if (stringLength < suffixLength) {
        return false;
    }
    const char *a = string + (stringLength - suffixLength);
    const char *b = suffix;
    int i = 0;
    while (i < suffixLength) {
        const char c = a[i];
        if (c != b[i++]) {
            return false;
        }
    }
    return true;
}
