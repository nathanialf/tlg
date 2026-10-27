/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkOstream &hkOstream::FUN_00008440(const char *string)
{
    if (string) {
        writer->write(string, FUN_00017fe0(string));
    } else {
        writer->write("(null)", 6);
    }
    return *this;
}
