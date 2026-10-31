/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

inline int hknpCompoundShapeInternalsKeyMask::instanceIndex(hknpShapeInstanceId instanceId) const
{
    return shape->instances.elements[instanceId.value].getIndex();
}

/* Slot 4: each instance with a mask of its own takes the mask's answer as
 * its bit in the filter (its index read before the mask is asked), then the
 * shape's tree is walked over the filter. */
bool hknpStaticCompoundShapeKeyMask::FUN_000381d0()
{
    for (int i = 0; i < instanceMasks.size; i++) {
        hknpShapeKeyMask *instanceMask = instanceMasks[i];
        if (instanceMask) {
            hknpShapeInstanceId instanceId;
            instanceId.value = short(i);
            const int index = instanceIndex(instanceId);
            u32 &word = filter[index / 32];
            const bool enabled = instanceMask->FUN_000381d0();
            word = (word & ~(1 << (index % 32))) | (u32(enabled) << (index % 32));
        }
    }
    return static_cast<const hknpStaticCompoundShape *>(shape)
        ->boundingVolumeData->aabbTree.anyLeafEnabled(filter.data);
}
