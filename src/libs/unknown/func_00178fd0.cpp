/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* One wheel's state for the step: its transform's rotation from the
 * chassis's orientation, the wheel's steering and the chassis frame with its
 * first two axes swapped, the transform at the hard point, and the cast's end
 * the suspension's length along its direction. */
inline void hknpVehicleLinearCastWheelCollide::updateWheelState(const hknpVehicleInstance *vehicle,
                                                                u8 wheelIndex)
{
    const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[wheelIndex];
    WheelState &wheelState = wheelStates[wheelIndex];

    hknpWorld *world = vehicle->world;
    const hknpBody &chassis = world->bodyManager.bodies[vehicle->bodyId.value];
    const hkQuaternion &chassisOrientation =
        world->motionManager.motions[chassis.motionId].orientation;
    hkQuaternion wheelOrientation;
    wheelOrientation.setMul(chassisOrientation, wheelInfo.steeringOrientationChassisSpace);

    const hkMatrix3 &frame = vehicle->data->chassisOrientation;
    hkMatrix3 rotation;
    rotation.col0 = frame.col1;
    rotation.col1 = frame.col0;
    rotation.col2 = frame.col2;
    hkQuaternion shapeOrientation; /* derived name */
    shapeOrientation.FUN_0001a1c0(rotation);
    wheelOrientation.setMul(wheelOrientation, shapeOrientation);
    wheelState.transform.rotation.FUN_0000bd30(wheelOrientation);

    wheelState.transform.translation = wheelInfo.hardPointWs;
    wheelState.to =
        _mm_add_ps(_mm_mul_ps(_mm_set1_ps(vehicle->suspension->wheelParams[wheelIndex].length),
                              wheelInfo.suspensionDirectionWs),
                   wheelInfo.hardPointWs);
}

void hknpVehicleLinearCastWheelCollide::updateBeforeCollisionDetection(
    const hknpVehicleInstance *vehicle)
{
    const int numWheels = wheelStates.size;
    for (u8 i = 0; i < numWheels; i++) {
        updateWheelState(vehicle, i);
    }
}
