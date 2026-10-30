/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkBool Object0000b330::FUN_0000b4a0(int id)
{
    criticalSection.enter();
    const hkBool enabled = int(map.FUN_00013b30(hkUlong(id), 0)) == 0;
    criticalSection.leave();
    return enabled;
}
