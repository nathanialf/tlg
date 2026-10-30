/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

ClassVersionIndex0019a0b0::~ClassVersionIndex0019a0b0()
{
    for (StringMap::Iterator it = ownedNames.FUN_00091600(); ownedNames.FUN_00013890(it);
         it = ownedNames.FUN_00091650(it)) {
        freeHeapString(reinterpret_cast<char *>(ownedNames.FUN_00091640(it)));
    }
}
