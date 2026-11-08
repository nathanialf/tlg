/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The mask of a shape: every leaf of the shape's tree on, then a mask of
 * its own for each live instance whose shape is a composite, indexed by
 * the instance's id, then the filter brought up to date (slot 4). */
// NONMATCHING: 106 of 172 (623 bytes against 625), two residuals. (1) With no instances the
// base goes straight to the masks' setSize with 1 (0xcfb24 to 0xcfb9e): the ids' size known 0
// on that edge; here the second jump threading threads only the reserve call's edge (the most
// popular destination of the doubled `n > 0` branch) and the other reaches the count's load
// through an empty block, where FindAvailableLoadedValue sees no store. (2) The base loads the
// shape's dispatch type into cl and compares the register (0xcfc16), where this compile folds
// the load into the compare. NOTES Round 79A.
hknpStaticCompoundShapeKeyMask::hknpStaticCompoundShapeKeyMask(
    const hknpStaticCompoundShape *shape_)
{
    shape = shape_;
    const int numLeaves = shape_->boundingVolumeData->aabbTree.nodes.getSize();
    filter.setSize(hkContainerHeapAllocator::get(), (numLeaves + 31) / 32, 0xffffffff);

    /* The ids of the instances in use. */
    hkArray<hknpShapeInstanceId> instanceIds;
    const int numInstances = shape_->instances.elements.getSize();
    instanceIds.reserve(hkContainerHeapAllocator::get(), numInstances);
    for (int i = 0; i < numInstances; i++) {
        hknpShapeInstanceId instanceId;
        instanceId.value = short(i);
        if (!hknpShapeInstance::isEmpty(shape_->instances[instanceId])) {
            instanceIds.pushBackUnchecked(instanceId);
        }
    }

    int maxId = 0;
    for (int i = 0; i < instanceIds.getSize(); i++) {
        maxId = hkMath::max2(maxId, int(instanceIds[i].value));
    }
    instanceMasks.setSize(hkContainerHeapAllocator::get(), maxId + 1, HK_NULL);

    for (int i = 0; i < instanceIds.getSize(); i++) {
        const hknpShape *instanceShape = shape_->instances[instanceIds[i]].shape;
        if (instanceShape->dispatchType == hknpCollisionDispatchType::COMPOSITE) {
            instanceMasks[instanceIds[i].value] = instanceShape->unknownVirtual20();
        }
    }
    FUN_000381d0();
}
