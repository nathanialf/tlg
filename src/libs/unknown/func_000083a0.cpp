/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkOstream &hkOstream::FUN_000083a0(hkBool b)
{
    const char *string = b ? "true" : "false";
    writer->write(string, FUN_00017fe0(string));
    return *this;
}
