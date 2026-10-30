/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpTriangleShape *hknpTriangleShape::FUN_000783f0(float convexRadius)
{
    void *storage = D_16dc070->temp58->blockAlloc(sizeof(InplaceTriangleShape00078160));
    hkString::memCpy16(storage, D_57c8818->triangleShapeStorage,
                       sizeof(InplaceTriangleShape00078160) / 16);
    hknpTriangleShape *shape = static_cast<hknpTriangleShape *>(storage);
    shape->convexRadius = convexRadius;
    return shape;
}
