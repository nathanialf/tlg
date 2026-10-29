/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpCogWheelConstraintData's constructor: the atoms typed, both frames
 * the identity, both wheels of radius 1 and the runtime's layout (the
 * initial angle offset at 8, the previous angle at 16, the revolution
 * counter at 24). */
hkpCogWheelConstraintData::hkpCogWheelConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.cogWheels.type = hkpConstraintAtom::TYPE_COG_WHEEL;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.cogWheels.cogWheelRadiusA = 1.0f;
    atoms.cogWheels.cogWheelRadiusB = 1.0f;
    atoms.cogWheels.isScrew = false;
    atoms.cogWheels.memOffsetToInitialAngleOffset = 8;
    atoms.cogWheels.memOffsetToPrevAngle = 16;
    atoms.cogWheels.memOffsetToRevolutionCounter = 24;
}
