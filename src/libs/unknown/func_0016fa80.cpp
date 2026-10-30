/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleDefaultSteering::calcMainSteeringAngle(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleFilteredDriverInput &filteredInfoOutput,
    SteeringAnglesOutput &steeringOutput) const
{
    steeringOutput.mainSteeringAngle = filteredInfoOutput.steeringWheelInput * maxSteeringAngle;
    steeringOutput.mainSteeringAngleAssumingNoReduction = steeringOutput.mainSteeringAngle;

    // The chassis's forward axis in world space, and its speed along it.
    Vec4 forward;
    FUN_00010ef0(forward,
                 vehicle->world->bodyManager.bodies[vehicle->bodyId.value].transform.rotation,
                 vehicle->data->chassisOrientation.col1);
    const hknpWorld *world = vehicle->world;
    const hknpMotion &motion =
        world->motionManager.motions[world->bodyManager.bodies[vehicle->bodyId.value].motionId];
    const Vec4 forwardSpeed = _mm_dp_ps(motion.linearVelocity, forward, 0x7f);
    const Vec4 fullAngleSpeed = _mm_set1_ps(maxSpeedFullSteeringAngle);
    if (_mm_ucomigt_ss(forwardSpeed, fullAngleSpeed)) {
        const Vec4 r = _mm_rcp_ps(forwardSpeed);
        const Vec4 inverse = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(forwardSpeed, r)));
        const Vec4 factor = _mm_mul_ps(fullAngleSpeed, inverse);
        steeringOutput.mainSteeringAngle *= _mm_cvtss_f32(_mm_mul_ps(factor, factor));
    }
}
