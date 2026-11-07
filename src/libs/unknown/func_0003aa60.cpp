/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBody::FUN_0003aa60(u32 bodyId, const hknpBodyCinfo &cinfo)
{
    aabb.setEmpty();
    motionId = 0x7fffffff;
    nextAttachedBodyId = 0x7fffffff;
    broadPhaseId = 0xffffffff;
    indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;
    radiusOfComCenteredBoundingSphere.setReal(1.0f);
    id = bodyId;

    /* The rotation and position; the columns' w lanes (the centre of mass)
     * kept, the translation's the look-ahead distance. */
    hkTransform t;
    t.rotation.FUN_0000bd30(cinfo.orientation);
    t.translation = cinfo.position;
    setTransformKeepingW(t);
    lane(transform.translation, 3) = cinfo.collisionLookAheadDistance;

    const hknpShape *oldShape = shape;
    const hknpShape *newShape = cinfo.shape;
    shape = newShape;
    if (newShape) {
        if (D_16dc5f8) {
            newShape->addReference();
        }
        const int value = newShape->unknownVirtual6();
        shapeSlot6Div16 = u8(value >> 4);
        if (value > 0x800 || (newShape->flags & hknpShape::SHAPE_NOT_SUPPORTED_ON_SPU)) {
            flags |= 0x10000000;
        }
    } else {
        shapeSlot6Div16 = 0;
    }
    if (oldShape && D_16dc5f8) {
        oldShape->removeReference();
    }

    materialId.value = cinfo.materialId;
    qualityId = cinfo.qualityId;
    collisionFilterInfo = cinfo.collisionFilterInfo;
    flags = (cinfo.flags & ~0x40f) | 0x400;
    userData = cinfo.userData;
}
