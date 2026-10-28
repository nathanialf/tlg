/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpConvexPolytopeShape::FUN_001520f0() const /* derived name */
{
    const int end = hkMath::max2(hkMath::max2(vertices.endOffset(this), planes.endOffset(this)),
                                 hkMath::max2(faces.endOffset(this), indices.endOffset(this)));
    const int size = (end + 15) & ~15;
    return end > int(sizeof(*this)) ? size : int(sizeof(*this));
}
