/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpHingeConstraintData::FUN_0007ede0(const Vec4 &pivotA, const Vec4 &pivotB, const Vec4 &axisA,
                                          const Vec4 &axisB)
{
    hkTransform &transformA = atoms.transforms.transformA;
    hkTransform &transformB = atoms.transforms.transformB;
    transformA.translation = pivotA;
    transformB.translation = pivotB;

    transformA.rotation.col0 = normalized3(axisA);
    transformA.rotation.col1 = normalized3(perpendicular3(transformA.rotation.col0));
    transformA.rotation.col2 = cross3(transformA.rotation.col0, transformA.rotation.col1);

    transformB.rotation.col0 = normalized3(axisB);
    transformB.rotation.col1 = normalized3(perpendicular3(transformB.rotation.col0));
    transformB.rotation.col2 = cross3(transformB.rotation.col0, transformB.rotation.col1);
}
