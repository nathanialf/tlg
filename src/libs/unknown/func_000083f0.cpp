/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkOstream &hkOstream::FUN_000083f0(char c)
{
    writer->write(&c, 1);
    return *this;
}
