/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkpRackAndPinionConstraintData's constructor: the atoms typed, both
 * frames the identity, a pinion of radius 1 and the runtime's layout (the
 * initial angle offset at 8, the previous angle at 12, the revolution
 * counter at 16). */
hkpRackAndPinionConstraintData::hkpRackAndPinionConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.rackAndPinion.type = hkpConstraintAtom::TYPE_RACK_AND_PINION;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.rackAndPinion.pinionRadiusOrScrewPitch = 1.0f;
    atoms.rackAndPinion.isScrew = false;
    atoms.rackAndPinion.memOffsetToInitialAngleOffset = 8;
    atoms.rackAndPinion.memOffsetToPrevAngle = 12;
    atoms.rackAndPinion.memOffsetToRevolutionCounter = 16;
}
