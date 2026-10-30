/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 4: the hit's position scaled, offset and transformed, its normal
 * scaled, rotated and renormalised, the hit added to the wrapped collector
 * and its early-out value taken. */
void hknpScaledOffsetQueryCollector::FUN_0016d090(const hknpCollisionResult &hit) /* derived name */
{
    hknpCollisionResult transformed = hit;
    transformed.position.quad =
        _mm_add_ps(_mm_mul_ps(transformed.position.quad, positionScale), positionOffset);
    transformed.position.quad = transformPosition(*transform, transformed.position.quad);
    transformed.normal.quad = _mm_mul_ps(transformed.normal.quad, normalScale);
    const hkMatrix3 &rotation = transform->rotation;
    transformed.normal.quad = normalized3Unchecked(
        combineColumns(rotation.col0, rotation.col1, rotation.col2, transformed.normal.quad));
    childCollector->addHit(transformed);
    earlyOut = childCollector->earlyOut;
}
