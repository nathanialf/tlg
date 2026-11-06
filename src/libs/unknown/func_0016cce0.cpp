/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The box is taken over the buffer as slot 10 filled it, the build over
 * the vertices slot 10 returned. */
void hknpScaledConvexShapeBase::FUN_0016cce0(const void *argument1, void *argument2) const
{
    const hknpConvexShape *core = static_cast<const hknpConvexShape *>(coreShape);
    LocalBuffer<Vec4> buffer(unknownVirtual9());
    const Vec4 *vertices = unknownVirtual10(buffer.data, unknownVirtual9());
    const int numVertices = FUN_001707d0(core);
    const MassConfig00168340 &config = *static_cast<const MassConfig00168340 *>(argument1);
    if (config.quality == 2) {
        FUN_00168d90(argument1, vertices, numVertices, argument2, convexRadius);
    } else {
        hkAabb aabb;
        aabb.setEmpty();
        for (int i = 0; i < numVertices; i++) {
            aabb.includePoint(buffer.data[i]);
        }
        const Vec4 radius = _mm_set1_ps(convexRadius);
        aabb.max = _mm_add_ps(aabb.max, radius);
        aabb.min = _mm_sub_ps(aabb.min, radius);
        FUN_00168230(config, aabb, *static_cast<hkDiagonalizedMassProperties *>(argument2));
    }
}
