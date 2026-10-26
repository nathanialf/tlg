/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hknpVehicleDefaultAerodynamics: the lift at a
 * speed, half the air density times the lift coefficient and the frontal
 * area, times the speed squared. */
float hknpVehicleDefaultAerodynamics::FUN_0003bf60(float speed) const
{
    return 0.5f * airDensity * liftCoefficient * frontalArea * (speed * speed);
}
