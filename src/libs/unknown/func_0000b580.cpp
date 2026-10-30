/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Object0000b330::FUN_0000b580() /* derived name */
{
    criticalSection.enter();
    unknown40 = 0;
    map.FUN_00013d80();
    criticalSection.leave();
}
