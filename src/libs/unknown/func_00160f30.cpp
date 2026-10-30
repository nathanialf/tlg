/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpBodyManager::FUN_00160f30(u32 bodyId, u16 value)
{
    if (bodyId >= u32(bodyEntries.size)) {
        if (value == 0xffff) {
            return;
        }
        bodyEntries.setSize(bodies.getCapacity());
    }
    bodyEntries[bodyId].value = value;
}
