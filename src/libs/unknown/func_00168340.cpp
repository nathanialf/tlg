/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a solid sphere's volume, mass and inertia about its centre;
 * a negative mass in the configuration is a density. */
hkResult FUN_00168340(const MassConfig00168340 &config, const Vec4 &center, float radius,
                      hkDiagonalizedMassProperties &propertiesOut)
{
    if (radius > 0.0f) {
        const float radiusSquared = radius * radius;
        const float volume = (4.0f / 3.0f) * HK_REAL_PI * radiusSquared * radius;
        propertiesOut.volume = volume;
        float mass = config.massOrNegativeDensity;
        if (mass < 0.0f) {
            mass = -(volume * mass);
        }
        propertiesOut.mass = mass;
        const float inertia = 0.4f * radiusSquared * mass * config.inertiaFactor;
        propertiesOut.inertiaTensor = _mm_set1_ps(inertia);
        propertiesOut.centerOfMass = setXYZ_0(center);
        propertiesOut.majorAxisSpace.vec = D_14b2060[32];
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}
