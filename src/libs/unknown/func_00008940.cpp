/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkOstream &hkOstream::FUN_00008940(const hkStringPtr &string)
{
    if (const char *chars = string.cString()) {
        writer->write(chars, string.FUN_0000e770());
    } else {
        writer->write("(null)", 6);
    }
    return *this;
}
