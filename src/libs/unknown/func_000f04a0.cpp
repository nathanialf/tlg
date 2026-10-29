/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpDynamicCompoundShape::unknownVirtual32(hknpShapeInstanceId instanceId,
                                                hkAabb &aabbOut) const
{
    const hkAabb &leaf =
        boundingVolumeData->nodes[instances.elements[instanceId.value].getLeafIndex()];
    aabbOut.max = setXYZ_0(leaf.max);
    aabbOut.min = leaf.min;
}
