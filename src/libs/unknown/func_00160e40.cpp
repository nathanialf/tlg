/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

float hknpBodyManager::FUN_00160e40(u32 bodyId, float value)
{
    if (bodyId >= u32(bodyEntries.size)) {
        if (value < 0.0f) {
            return -1.0f;
        }
        bodyEntries.setSize(bodies.getCapacity());
    }
    bodyEntries[bodyId].half.setReal(value * (1.0f + 1.0f / 256.0f));
    return bodyEntries[bodyId].half.getReal();
}
