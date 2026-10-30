/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpSphereShape *hknpSphereShape::FUN_0003c580(const Vec4 &center, float radius)
{
    const int numBytes = sizeof(hknpSphereShape) + 4 * sizeof(Vec4);
    void *storage = D_16dc070->temp58->blockAlloc(numBytes);
    hknpSphereShape *sphere = new (storage) hknpSphereShape(center, radius);
    sphere->setMemSize(numBytes);
    return sphere;
}
