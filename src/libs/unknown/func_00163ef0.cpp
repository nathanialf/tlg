/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleInstance::FUN_00163ef0(float deltaTime, const u32 *groundBodyIds,
                                       const hknpVehicleFrictionSolverParams &params)
{
    for (int i = 0; i < data->numWheels; i++) {
        const int axle = data->wheelParams[i].axle;
        WheelInfo &wheel = wheelsInfo[i];
        const AxisStatus &status = frictionStatus[axle];

        float skidEnergyDensity = 0.0f;
        if (wheel.contactBodyId.value != 0x7fffffff) {
            const hknpBody &ground = world->bodyManager.bodies[wheel.contactBodyId.value];
            if (world->motionManager.motions[ground.motionId].solverId == 0) {
                skidEnergyDensity = status.skidEnergyDensity;
            }
        }
        wheel.skidEnergyDensity = skidEnergyDensity;
        wheel.sideForce = status.sideForce;
        wheel.sideSlipVelocity = status.sideSlipVelocity;
        wheel.forwardSlipVelocity = status.forwardSlipVelocity;

        Vec4 forward;
        FUN_00010ef0(forward, world->bodyManager.bodies[bodyId.value].transform.rotation,
                     data->chassisOrientation.col1);

        if (isFixed[i]) {
            wheel.spinVelocity = 0.0f;
            wheel.noSlipIdealSpinVelocity = 0.0f;
        } else {
            float groundVelocity =
                _mm_cvtss_f32(_mm_dp_ps(forward, params.chassis.linearVelocity, 0x7f));
            if (groundBodyIds[axle] != 0x7fffffff) {
                groundVelocity -= _mm_cvtss_f32(
                    _mm_dp_ps(forward, params.axleParams[axle].groundObject->linearVelocity, 0x7f));
            }
            wheel.noSlipIdealSpinVelocity = groundVelocity / data->wheelParams[i].radius;
            wheel.spinVelocity =
                (groundVelocity + wheel.forwardSlipVelocity) / data->wheelParams[i].radius;
            wheel.spinAngle += wheel.spinVelocity * deltaTime;
        }
    }
}
