/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 19: the plane's normal, the lin atom's axis column of the second
 * frame's rotation under the rotation given, scaled. The frame is declared
 * before the rotation's columns are read: its lifetime marker then sits
 * before every load, one chain step shallower, and the first column's z
 * product is scheduled first as the base holds it (cookbook 270). */
void hkpPointToPlaneConstraintData::FUN_0007b5a0(const void *argument1, const void *argument2,
                                                 const void *argument3, Vec4 &out) const
{
    const hkMatrix3 &rotation = *static_cast<const hkMatrix3 *>(argument2);
    const hkMatrix3 &frameB = atoms.transforms.transformB.rotation;
    hkMatrix3 frame;
    const Vec4 c0 = rotation.col0;
    const Vec4 c1 = rotation.col1;
    const Vec4 c2 = rotation.col2;
    frame.col0 = combineColumns(c0, c1, c2, frameB.col0);
    frame.col1 = combineColumns(c0, c1, c2, frameB.col1);
    frame.col2 = combineColumns(c0, c1, c2, frameB.col2);
    const Vec4 scale = _mm_set1_ps(*static_cast<const float *>(argument3));
    out = _mm_mul_ps(scale, frame.getColumn(atoms.lin.axisIndex));
}
