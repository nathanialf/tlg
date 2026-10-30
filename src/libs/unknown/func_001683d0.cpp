/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkResult FUN_001683d0(const MassConfig00168340 &config, const Vec4 &start, const Vec4 &end,
                      float radius, hkDiagonalizedMassProperties &propertiesOut)
{
    hkMassProperties massProperties;
    const hkResult result = FUN_00028b80(start, end, radius, 1.0f, massProperties);
    if (result == HK_SUCCESS) {
        propertiesOut.FUN_00026300(massProperties);
        float mass = config.massOrNegativeDensity;
        if (mass < 0.0f) {
            mass = -(mass * propertiesOut.volume);
        }
        propertiesOut.inertiaTensor =
            _mm_mul_ps(_mm_set1_ps(mass * config.inertiaFactor), propertiesOut.inertiaTensor);
        propertiesOut.mass = mass;
    }
    return result;
}
