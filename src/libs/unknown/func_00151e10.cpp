/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 11 of hknpVehicleDefaultAnalogDriverInput's vtable
 * (address point 0x16a43d0), the steering input: the stick's x past the
 * dead zone, scaled by the initial slope up to the change point and from
 * there along the line that reaches 1 at full deflection, signed as the
 * stick is. */
float hknpVehicleDefaultAnalogDriverInput::FUN_00151e10(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleDriverInputAnalogStatus *status, hknpVehicleFilteredDriverInput &output) const
{
    const float x = status->positionX;
    const float absX = hkMath::fabs(x);
    if (absX < deadZone) {
        return 0.0f;
    }
    const float sign = x > 0.0f ? 1.0f : -1.0f;
    float input;
    if (absX < slopeChangePointX) {
        input = (absX - deadZone) * initialSlope;
    } else {
        const float inputAtChange = (slopeChangePointX - deadZone) * initialSlope;
        const float slope = (1.0f - inputAtChange) / (1.0f - slopeChangePointX);
        input = inputAtChange + (absX - slopeChangePointX) * slope;
    }
    return sign * input;
}
