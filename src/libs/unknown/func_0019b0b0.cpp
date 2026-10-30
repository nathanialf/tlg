/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkRelocationInfo::~hkRelocationInfo()
{
    StringMap *const strings = pool;
    if (strings) {
        strings->FUN_00180bf0();
        delete strings;
    }
}
