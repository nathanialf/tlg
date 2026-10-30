/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 5 of hknpVehicleDefaultSuspension's vtable (address point
 * 0x16a4050). */
void hknpVehicleDefaultSuspension::FUN_0014dfa0(const hknpVehicleInstance *vehicle,
                                                const WheelCollideOutput *cdInfo,
                                                float *suspensionForceOut)
{
    const hknpWorld *world = vehicle->world;
    const hknpMotion &motion =
        world->motionManager.motions[world->bodyManager.bodies[vehicle->bodyId.value].motionId];
    const Vec4 inverseInertia = loadHalves(motion.inverseInertia);
    const float chassisMass = _mm_cvtss_f32(simdReciprocalOrZero(
        _mm_shuffle_ps(inverseInertia, inverseInertia, _MM_SHUFFLE(3, 3, 3, 3))));
    for (int i = 0; i < vehicle->data->numWheels; i++) {
        const WheelCollideOutput &cd = cdInfo[i];
        if (cd.contactBodyId.value == 0x7fffffff) {
            suspensionForceOut[i] = 0.0f;
            continue;
        }
        const float lengthDiff = wheelParams[i].length - cd.currentSuspensionLength;
        const float damping = cd.suspensionClosingSpeed < 0.0f
                                  ? wheelSpringParams[i].dampingCompression
                                  : wheelSpringParams[i].dampingRelaxation;
        const float force =
            lengthDiff * wheelSpringParams[i].strength * cd.suspensionScalingFactor -
            cd.suspensionClosingSpeed * damping;
        suspensionForceOut[i] = chassisMass * force;
    }
}
