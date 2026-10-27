/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

bool FUN_0001a770(const char *name, const char *pattern) /* derived name */
{
    if (name[0] == 0) {
        return false;
    }
    if (name[0] == '.' && (name[1] == 0 || (name[1] == '.' && name[2] == 0))) {
        return false;
    }
    if (!pattern) {
        return true;
    }
    return FUN_000181c0(name, pattern + 1);
}
