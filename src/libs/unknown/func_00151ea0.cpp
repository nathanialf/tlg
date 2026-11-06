/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* With automatic reverse: reversing when the stick is pulled back while the
 * chassis moves against its forward axis, or, slower than five kilometres
 * an hour, while it is pulled back; once reversing, until it is let go
 * below that speed. Without, the reverse button. */
hkBool hknpVehicleDefaultAnalogDriverInput::FUN_00151ea0(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleDriverInputAnalogStatus *status, hknpVehicleFilteredDriverInput &output) const
{
    if (!autoReverse) {
        return status->reverseButtonPressed;
    }
    const hknpBody &body = vehicle->world->bodyManager.bodies[vehicle->bodyId.value];
    const Vec4 linearVelocity = vehicle->world->motionManager.motions[body.motionId].linearVelocity;
    const hkBool wasReversing = vehicle->isReversing;
    const float input = status->positionY;
    const Vec4 speed = length3(linearVelocity);
    // Five kilometres an hour in metres a second, one factor.
    const hkBool32 slow = _mm_ucomilt_ss(speed, _mm_set1_ps(5.0f / 3.6f));
    if (input > 0.1f && _mm_ucomigt_ss(speed, D_14b2060[35])) {
        const Vec4 &axis = vehicle->data->chassisOrientation.col1;
        const Vec4 x = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(0, 0, 0, 0));
        const Vec4 y = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(1, 1, 1, 1));
        const Vec4 z = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(2, 2, 2, 2));
        const hkMatrix3 &rotation = body.transform.rotation;
        const Vec4 forward =
            _mm_add_ps(_mm_mul_ps(z, rotation.col2),
                       _mm_add_ps(_mm_mul_ps(x, rotation.col0), _mm_mul_ps(y, rotation.col1)));
        const Vec4 cosine = _mm_dp_ps(normalized3(linearVelocity), normalized3(forward), 0x7f);
        if (_mm_ucomilt_ss(cosine, D_14b2060[35])) {
            return true;
        }
    }
    if (wasReversing) {
        return slow ? hkBool(input > 0.1f) : hkBool(true);
    }
    return slow && input > 0.1f;
}
