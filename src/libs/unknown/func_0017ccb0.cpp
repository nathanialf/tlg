/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkpWheelConstraintData::unknownVirtual7() const
{
    hkTransform steeringA;
    steeringA.set(atoms.steeringBase.rotationA, D_14b2060[2]);
    hkTransform steeringB;
    steeringB.set(atoms.steeringBase.rotationB, D_14b2060[2]);
    return atoms.suspensionBase.transformA.rotation.FUN_0000bde0() &&
           atoms.suspensionBase.transformB.rotation.FUN_0000bde0() &&
           steeringA.rotation.FUN_0000bde0() && steeringB.rotation.FUN_0000bde0() &&
           atoms.lin0Limit.min <= atoms.lin0Limit.max;
}
