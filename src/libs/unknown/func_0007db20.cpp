/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpRagdollConstraintData::FUN_0007db20(const Vec4 &pivotA, const Vec4 &pivotB,
                                            const Vec4 &planeAxisA, const Vec4 &planeAxisB,
                                            const Vec4 &twistAxisA, const Vec4 &twistAxisB)
{
    hkTransform &transformA = atoms.transforms.transformA;
    hkTransform &transformB = atoms.transforms.transformB;

    transformA.rotation.col0 = normalized3(twistAxisA);
    transformA.rotation.col1 = normalized3(planeAxisA);
    transformA.rotation.col2 = cross3(transformA.rotation.col0, transformA.rotation.col1);
    transformA.translation = pivotA;

    transformB.rotation.col0 = normalized3(twistAxisB);
    transformB.rotation.col1 = normalized3(planeAxisB);
    transformB.rotation.col2 = cross3(transformB.rotation.col0, transformB.rotation.col1);
    transformB.translation = pivotB;

    atoms.ragdollMotors.target_bRca = transformB.rotation;
}
