/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpCompoundShape::FUN_000418c0(void *keysOut, int maxNumKeys, int key,
                                    const ShapeKeyQuery000380b0 &query) const
{
    ShapeKeyQuery000380b0 childQuery = query;
    u32 childKey = 0xffffffff;
    int firstIndex = 0;
    if (u32(key) != 0xffffffff) {
        childKey = u32(key) << numShapeKeyBits;
        firstIndex = u32(key) >> (32 - numShapeKeyBits);
    }
    int numKeys = 0;
    const int numInstances = instances.elements.getSize();
    for (int i = firstIndex; i < numInstances; i++) {
        hknpShapeInstanceId instanceId;
        instanceId.value = short(i);
        const hknpShapeInstance &instance = instances[instanceId];
        if (!hknpShapeInstance::isEmpty(instance) &&
            (instance.getFlags() & hknpShapeInstance::IS_ENABLED)) {
            if (!query.mask || static_cast<const hknpCompoundShapeKeyMask *>(query.mask)
                                   ->FUN_00033d30(instanceId)) {
                childQuery.path = query.path;
                childQuery.path.appendSubKey(i, numShapeKeyBits);
                childQuery.mask = HK_NULL;
                numKeys +=
                    instance.shape->unknownVirtual21(static_cast<u32 *>(keysOut) + numKeys,
                                                     maxNumKeys - numKeys, childKey, childQuery);
                if (numKeys == maxNumKeys) {
                    return maxNumKeys;
                }
            }
        }
        childKey = 0xffffffff;
    }
    return numKeys;
}
