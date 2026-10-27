/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkOstream &hkOstream::FUN_000089a0(const hkStringBuf &string)
{
    if (string.string.data) {
        writer->write(string.string.data, string.getLength());
    } else {
        writer->write("(null)", 6);
    }
    return *this;
}
