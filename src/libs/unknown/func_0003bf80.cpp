/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hknpVehicleDefaultAerodynamics::calcAerodynamics(float deltaTime,
                                                      const hknpVehicleInstance *vehicle,
                                                      AerodynamicsDragOutput &dragInfoOut)
{
    const hknpBody &chassis = vehicle->world->bodyManager.bodies[vehicle->bodyId.value];
    const Vec4 col0 = chassis.transform.rotation.col0;
    const Vec4 col1 = chassis.transform.rotation.col1;
    const Vec4 col2 = chassis.transform.rotation.col2;
    const hkMatrix3 &chassisOrientation = vehicle->data->chassisOrientation;
    const hknpMotion &motion = vehicle->world->motionManager.motions[chassis.motionId];

    const Vec4 forward = combineColumns(col0, col1, col2, chassisOrientation.col1);
    const Vec4 up = combineColumns(col0, col1, col2, chassisOrientation.col0);
    const float forwardSpeed = _mm_cvtss_f32(_mm_dp_ps(forward, motion.linearVelocity, 0x7f));

    const float drag = FUN_0003bf20(forwardSpeed);
    const float lift = FUN_0003bf60(forwardSpeed);
    dragInfoOut.aerodynamicsForce =
        _mm_add_ps(_mm_mul_ps(forward, _mm_set1_ps(drag)), _mm_mul_ps(up, _mm_set1_ps(lift)));

    const Vec4 inverseMass = loadHalves(motion.inverseInertia);
    const Vec4 mass =
        simdReciprocalOrZero(_mm_shuffle_ps(inverseMass, inverseMass, _MM_SHUFFLE(3, 3, 3, 3)));
    dragInfoOut.aerodynamicsForce =
        _mm_add_ps(dragInfoOut.aerodynamicsForce, _mm_mul_ps(mass, extraGravityws));
    dragInfoOut.aerodynamicsTorque = _mm_setzero_ps();
}
