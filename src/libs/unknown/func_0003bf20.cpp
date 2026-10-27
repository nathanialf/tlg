/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleDefaultAerodynamics: the drag at a
 * speed, against it: minus half the air density times the drag coefficient
 * and the frontal area, times the speed's magnitude and the speed. */
float hknpVehicleDefaultAerodynamics::FUN_0003bf20(float speed) const
{
    const float absSpeed = hkMath::fabs(speed);
    return -0.5f * airDensity * dragCoefficient * frontalArea * absSpeed * speed;
}
