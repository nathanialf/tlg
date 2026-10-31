/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpShapeInstance::FUN_0003ed80(hkAabb &aabbOut) const /* derived name */
{
    const int flags = getFlags();
    float radius = shape->convexRadius;
    hkVector4 instanceScale = scale;
    hkTransform scaledTransform;
    scaledTransform.translation = transform.translation;
    if ((flags & HAS_SCALE) && shape->dispatchType == hknpCollisionDispatchType::CONVEX) {
        const hknpConvexShape *convex = shape->asConvexShape();
        Vec4 offset;
        FUN_00169c90(convex->unknownVirtual5(), convex->vertices.beginBytes(),
                     convex->vertices.getSize(), !(flags & SCALE_SURFACE), instanceScale.quad,
                     radius, offset);
        FUN_00010ef0(offset, transform.rotation, offset);
        scaledTransform.translation = _mm_add_ps(scaledTransform.translation, offset);
    }
    scaledTransform.rotation.col0 =
        _mm_mul_ps(broadcast<0>(instanceScale.quad), transform.rotation.col0);
    scaledTransform.rotation.col1 =
        _mm_mul_ps(broadcast<1>(instanceScale.quad), transform.rotation.col1);
    scaledTransform.rotation.col2 =
        _mm_mul_ps(broadcast<2>(instanceScale.quad), transform.rotation.col2);
    /* Slot 7 takes the transform as the tree's Mat4 (its rows the
     * rotation's columns, then the translation). */
    shape->unknownVirtual7(reinterpret_cast<const Mat4 &>(scaledTransform), aabbOut);
    const Vec4 grown = simdFromFloat(radius - shape->convexRadius);
    aabbOut.max = _mm_add_ps(grown, aabbOut.max);
    aabbOut.min = _mm_sub_ps(aabbOut.min, grown);
}
