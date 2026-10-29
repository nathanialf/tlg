/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkp6DofConstraintData::Blueprints' finish constructor: the motors'
 * runtime offsets, in the compiled runtime's layout. */
hkp6DofConstraintData::Blueprints::Blueprints(hkFinishLoadedObjectFlag flag)
    : ragdollMotors(flag), linearMotor0(flag), linearMotor1(flag), linearMotor2(flag)
{
    if (flag.finishing) {
        ragdollMotors.initializedOffset = 152;
        ragdollMotors.previousTargetAnglesOffset = 160;
        linearMotor0.initializedOffset = 155;
        linearMotor0.previousTargetPositionOffset = 172;
        linearMotor1.initializedOffset = 156;
        linearMotor1.previousTargetPositionOffset = 176;
        linearMotor2.initializedOffset = 157;
        linearMotor2.previousTargetPositionOffset = 180;
    }
}
