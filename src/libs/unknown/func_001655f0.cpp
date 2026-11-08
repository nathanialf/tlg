/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A wheel's current place and orientation (Havok's
 * calcCurrentPositionAndRotation): the chassis's orientation, the wheel's
 * steering, the vehicle's forward frame (the data's orientation with its
 * first two columns exchanged) and the wheel's spin about its axis taken
 * into that frame; the hard point under the chassis transform moved along
 * the suspension by its length, none when negative. derived name. */
void hknpVehicleInstance::FUN_001655f0(const hkTransform &chassisTransform,
                                       const hknpVehicleSuspension *suspension, int wheelIndex,
                                       Vec4 &posOut, hkQuaternion &rotOut) const
{
    const hkMatrix3 &chassisOrientationCs = data->chassisOrientation;
    const WheelInfo &wheel = wheelsInfo[wheelIndex];
    hkQuaternion forwardOrientationQ;
    hkMatrix3 forwardOrientation;
    forwardOrientation.col0 = chassisOrientationCs.col1;
    forwardOrientation.col1 = chassisOrientationCs.col0;
    forwardOrientation.col2 = chassisOrientationCs.col2;
    forwardOrientationQ.FUN_0001a1c0(forwardOrientation);
    const float spinAngle = wheel.spinAngle;
    Vec4 spinAxis;
    FUN_000110c0(spinAxis, forwardOrientationQ, wheel.spinAxisChassisSpace);
    hkQuaternion spinRotation;
    spinRotation.FUN_00019e70(spinAxis, -spinAngle);
    hkQuaternion chassisOrientation;
    chassisOrientation.FUN_0001a1c0(chassisTransform.rotation);
    hkQuaternion steered;
    steered.setMul(chassisOrientation, wheel.steeringOrientationChassisSpace);
    hkQuaternion forward;
    forward.setMul(steered, forwardOrientationQ);
    rotOut.setMul(forward, spinRotation);

    const float suspensionLength = hkMath::max2(0.0f, wheel.currentSuspensionLength);
    posOut = transformPosition(chassisTransform,
                               suspension->wheelParams[wheelIndex].hardpointChassisSpace.quad);
    posOut =
        _mm_add_ps(_mm_mul_ps(_mm_set1_ps(suspensionLength), wheel.suspensionDirectionWs), posOut);
}
