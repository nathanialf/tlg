/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 29 (0x42300): the geometry of every enabled instance the input's
 * mask passes, each instance's shape asked for its own with the input's
 * mode and the defaults, then appended under the instance's transform; a
 * convex shape under a scale is asked through a scaled convex shape built
 * in place, under the transform without the scale. A failure when no
 * triangle was made. derived names. */
// NONMATCHING: greedy's assignment, 129 of 175 in order at the base's frame layout: the base keeps the
// input in r13 from the entry (spilled, reloaded before the mode is read) and takes the instance's
// address after the mask's call, where this keeps the instance in r12 from the header and the input
// only in its spill slot (the slot order then moves the frame by 0x10).
int hknpCompoundShape::FUN_00042300(const hknpShapeSlot29Input &input,
                                    hkGeometry *geometryOut) const
{
    geometryOut->FUN_00093c70();
    const int numInstances = instances.elements.getSize();
    for (int i = 0; i < numInstances; i++) {
        hknpShapeInstanceId instanceId;
        instanceId.value = short(i);
        const hknpShapeInstance &instance = instances[instanceId];
        if (hknpShapeInstance::isEmpty(instance) ||
            !(instance.getFlags() & hknpShapeInstance::IS_ENABLED)) {
            continue;
        }
        if (input.mask &&
            !static_cast<const hknpCompoundShapeKeyMask *>(input.mask)->FUN_00033d30(instanceId)) {
            continue;
        }

        const hknpShape *shape = instance.shape;
        const hknpShape::ShapeType shapeType = shape->unknownVirtual5();
        hkTransform transform;
        alignas(16) u8 scaledShapeBuffer[sizeof(hknpScaledConvexShapeBase)];
        if (!(instance.getFlags() & hknpShapeInstance::HAS_SCALE) ||
            (shapeType != hknpShape::SHAPE_TYPE_CONVEX &&
             shapeType != hknpShape::SHAPE_TYPE_CONVEX_POLYTOPE)) {
            instance.FUN_0003ea90(transform);
        } else {
            const int scaleMode = (instance.getFlags() & hknpShapeInstance::SCALE_SURFACE) ? 0 : 1;
            hknpScaledConvexShapeBase *scaledShape = new (scaledShapeBuffer)
                hknpScaledConvexShapeBase(shape->asConvexShape(), instance.scale.quad, scaleMode);
            scaledShape->setMemSize(0);
            shape = scaledShape;
            transform = instance.transform;
        }

        hkGeometry geometry;
        shape->unknownVirtual29(hknpShapeSlot29Input(input.mode), &geometry);
        geometryOut->appendGeometry(geometry, transform);
    }
    return geometryOut->triangles.getSize() ? HK_SUCCESS : HK_FAILURE;
}
