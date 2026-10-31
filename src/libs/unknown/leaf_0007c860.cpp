/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The atoms' types and defaults; the cone's stabilization turned on through
 * the switch below, which this file defines and so inlines (the finish
 * callback's file calls it, 0x788f0). */
hkpRagdollLimitsData::hkpRagdollLimitsData()
{
    atoms.rotations.type = hkpConstraintAtom::TYPE_SET_LOCAL_ROTATIONS;
    atoms.twistLimit.type = hkpConstraintAtom::TYPE_TWIST_LIMIT;
    atoms.twistLimit.isEnabled = true;
    atoms.coneLimit.type = hkpConstraintAtom::TYPE_CONE_LIMIT;
    atoms.coneLimit.isEnabled = true;
    atoms.coneLimit.memOffsetToAngleOffset = 0;
    atoms.planesLimit.type = hkpConstraintAtom::TYPE_CONE_LIMIT;
    atoms.planesLimit.isEnabled = true;
    atoms.planesLimit.memOffsetToAngleOffset = 0;

    atoms.rotations.rotationA.setIdentity();
    atoms.rotations.rotationB.setIdentity();

    atoms.twistLimit.twistAxis = 0;
    atoms.twistLimit.refAxis = 1;
    atoms.twistLimit.minAngle = -0.5236f;
    atoms.twistLimit.maxAngle = 0.5236f;
    atoms.twistLimit.angularLimitsTauFactor = 0.8f;
    atoms.twistLimit.angularLimitsDampFactor = 1.0f;

    atoms.coneLimit.twistAxisInA = 0;
    atoms.coneLimit.refAxisInB = 0;
    atoms.coneLimit.angleMeasurementMode = 0;
    atoms.coneLimit.minAngle = -100.0f;
    atoms.coneLimit.maxAngle = 1.0f;
    atoms.coneLimit.angularLimitsTauFactor = 0.8f;
    atoms.coneLimit.angularLimitsDampFactor = 1.0f;
    FUN_0007c860(true);

    atoms.planesLimit.twistAxisInA = 0;
    atoms.planesLimit.refAxisInB = 1;
    atoms.planesLimit.angleMeasurementMode = 1;
    atoms.planesLimit.minAngle = -0.025f;
    atoms.planesLimit.maxAngle = 0.025f;
    atoms.planesLimit.angularLimitsTauFactor = 0.8f;
    atoms.planesLimit.angularLimitsDampFactor = 1.0f;
}

/* Turn the cone limit's stabilization on or off: when on, the cone keeps its
 * angle offset 16 bytes into the constraint's runtime. */
void hkpRagdollLimitsData::FUN_0007c860(hkBool enable) /* derived name */
{
    atoms.coneLimit.memOffsetToAngleOffset = enable ? 16 : 0;
}
