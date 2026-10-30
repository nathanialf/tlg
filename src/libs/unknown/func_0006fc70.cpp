/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 28's default: the shape's bounds in its own space
 * (slot 7 under the identity), handed on with both arguments. */
void hknpShape::FUN_0006fc70(const void *argument1, void *argument2) const
{
    hkAabb aabb;
    unknownVirtual7(identityTransform(), aabb);
    FUN_00168230(*static_cast<const MassConfig00168340 *>(argument1), aabb,
                 *static_cast<hkDiagonalizedMassProperties *>(argument2));
}
