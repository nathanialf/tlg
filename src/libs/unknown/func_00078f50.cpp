/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpLimitedHingeConstraintData::FUN_00078f50(const Vec4 &pivotA, const Vec4 &pivotB,
                                                 const Vec4 &axisA, const Vec4 &axisB,
                                                 const Vec4 &axisAPerp, const Vec4 &axisBPerp)
{
    hkTransform &transformA = atoms.transforms.transformA;
    transformA.rotation.col0 = normalized3(axisA);
    transformA.rotation.col1 = normalized3(axisAPerp);
    transformA.rotation.col2 = cross3(transformA.rotation.col0, transformA.rotation.col1);
    transformA.translation = pivotA;

    hkTransform &transformB = atoms.transforms.transformB;
    transformB.rotation.col0 = normalized3(axisB);
    transformB.rotation.col1 = normalized3(axisBPerp);
    transformB.rotation.col2 = cross3(transformB.rotation.col0, transformB.rotation.col1);
    transformB.translation = pivotB;
}
